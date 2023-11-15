#include "PlayerObject.h"
#include "../../GameManager.h"
#include "../states/IdleState.h"
#include "../../combat/Attack.h"
#include <curses.h>
#include <random>
#include <string>
#include <utility>
#include <vector>

#ifndef _WIN32
#include <ncurses.h>
#endif

PlayerObject::PlayerObject(int health, int armor, int attack, int precision, int x, int y):
                healthPoints_(health),
                armorPoints_(armor),
                positionX_(x),
                positionY_(y),
                currentAttack_((new Attack(AttackType::BASIC, 5, 100))),
                characterState_(new IdleState()){

}

void PlayerObject::addAttack(Attack* attack){

    // No validate on attack for now
    this->attacks_.push_back(attack);
}

void PlayerObject::setAttackType(AttackType attackType){

    for (size_t i=0; i<this->attacks_.size(); i++){
        if (attacks_.at(static_cast<int>(i))->type == attackType){
            this->currentAttack_ = attacks_.at(static_cast<int>(i));
        }
    }
}

int PlayerObject::getHealthPoints() const {
    return healthPoints_;
}

int PlayerObject::getArmorPoints() const {
    return armorPoints_;
}

Attack* PlayerObject::getCurrentAttack() const{
    return this->currentAttack_;
}

void PlayerObject::setState(CharacterState* newState) {
    if (this->characterState_ != nullptr){
        delete characterState_;
    }
    this->characterState_ = newState;
}

CharacterState* PlayerObject::getCurrentState() const {
    return this->characterState_;
}

CharacterState* PlayerObject::getPreviousState() const {
    return this->characterState_;
}

std::pair<int, int> PlayerObject::getPosition() const {
    // It gives an error if you compile with older c++ standard
    std::pair<int, int> position = {positionX_, positionY_};
    return position;
}

void PlayerObject::takeDamage(int damage){
    this->healthPoints_ -= damage;
}

void PlayerObject::performAttack(AbstractEntity* entity){
    
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
        // Entity is the enemy NPC since the player can attack only NPCs
        entity->takeDamage(this->currentAttack_->damage);
        mvprintw(
                GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_X")+((GameManager::GetInstance()->getSetting("W_HEIGHT"))/2)-1,
                GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_Y"),
                ("Player hits for " + std::to_string(this->currentAttack_->damage)).c_str()
                );
    }else{
        // attack missed screen
    }
    GameManager::GetInstance()->toNextTurn();
}

bool PlayerObject::isAlive() const{
    return healthPoints_ > 0;
}

void PlayerObject::move(int deltaX, int deltaY){

    int boundX = GameManager::GetInstance()->getSetting("W_HEIGHT");
    int boundY = GameManager::GetInstance()->getSetting("W_WIDTH");
    

   // If the new position is inside the map, move the entity
   if (((this->positionX_ + deltaX) < boundX && (this->positionX_ + deltaX) >= 0) &&
       ((this->positionY_ + deltaY) < boundY && (this->positionY_ + deltaY) >= 0)){

       this->positionX_ += deltaX; 
       this->positionY_ += deltaY;
   }

}
