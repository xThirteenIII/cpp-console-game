#include "NPCObject.h"
#include "../../GameManager.h"
#include "../states/CharacterState.h"
#include "../states/IdleState.h"
#include "../../combat/Attack.h"
#include <algorithm>
#include <random>
#include <utility>
#include <vector>

NPCObject::NPCObject(int health, int armor, int attack, int precision, int x, int y):
                healthPoints_(health),
                armorPoints_(armor),
                positionX_(x),
                positionY_(y),
                currentAttack_((new Attack(AttackType::BASIC, 3, 100))),
                characterState_(new IdleState()){


}


int NPCObject::getHealthPoints() const {
    return healthPoints_;
}
int NPCObject::getArmorPoints() const {
    return armorPoints_;
}

void NPCObject::addAttack(Attack* attack){

    // No validate on attack for now
    this->attacks_.push_back(attack);
}

void NPCObject::setAttackType(AttackType attackType){

    // Search for specific attackType in attacks_ vector and set the corresponding attack as current
    // if found.
    for (size_t i=0; i<this->attacks_.size(); i++){
        if (attacks_.at(static_cast<int>(i))->type == attackType){
            this->currentAttack_ = attacks_.at(static_cast<int>(i));
        }
    }
}


void NPCObject::setState(CharacterState* newState) {
    if (this->characterState_ != nullptr){
        delete characterState_;
    }
    this->characterState_ = newState;
}

Attack* NPCObject::getCurrentAttack() const{
    return this->currentAttack_;
}

CharacterState* NPCObject::getCurrentState() const {
    return this->characterState_;
}

CharacterState* NPCObject::getPreviousState() const {
    return this->characterState_;
}

void NPCObject::takeDamage(int damage){
    this->healthPoints_ -= damage;
}

void NPCObject::performAttack(AbstractEntity* entity){
    
    // Enemy attacks with this->Attack.damage and the attack hits
    // based on the hit chance of the attack
    //
    // Generate a random number between 0 and 100
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 100);
    int randomValue = dis(gen);

    // If the number is within the hitChance, the attacks hits
    // Otherwise it fails
    if (randomValue <= this->currentAttack_->hitChance){
        // Entity is the player since the NPC attacks the player only for now
        entity->takeDamage(this->currentAttack_->damage);
        mvprintw(
                (GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_X")+(GameManager::GetInstance()->getSetting("W_HEIGHT")/2)-1),
                GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_Y"),
                ("Enemy hits for " + std::to_string(this->currentAttack_->damage)).c_str()
                );
                refresh();
    }else{
        // Attack missed
    }
    GameManager::GetInstance()->toNextTurn();
}


std::pair<int, int> NPCObject::getPosition() const {

    // It gives an error if you compile with older c++ standard
    std::pair<int, int> position = {positionX_, positionY_};
    return position;
}

bool NPCObject::isAlive() const{
    return healthPoints_ > 0;
}


void NPCObject::move(int deltaX, int deltaY){

    int boundX = GameManager::GetInstance()->getSetting("W_HEIGHT");
    int boundY = GameManager::GetInstance()->getSetting("W_WIDTH");
    

   // If the new position is inside the map, move the entity
   if (((this->positionX_ + deltaX) < boundX && (this->positionX_ + deltaX) >= 0) &&
       ((this->positionY_ + deltaY) < boundY && (this->positionY_ + deltaY) >= 0)){

       this->positionX_ += deltaX; 
       this->positionY_ += deltaY;
   }

}
