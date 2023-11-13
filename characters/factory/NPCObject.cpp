#include "NPCObject.h"
#include "../../GameManager.h"
#include "../states/CharacterState.h"
#include "../states/IdleState.h"
#include <utility>

NPCObject::NPCObject(int health, int armor, int attack, int precision, int x, int y):
                healthPoints_(health),
                armorPoints_(armor),
                attackPoints_(attack),
                hitChance_(precision),
                positionX_(x),
                positionY_(y),
                characterState_(nullptr){
                // Character constructor with no args sets state to Idle
    this->characterState_ = new IdleState();
}


int NPCObject::getHealthPoints() const {
    return healthPoints_;
}
int NPCObject::getArmorPoints() const {
    return armorPoints_;
}
int NPCObject::getAttackPoints() const {
    return attackPoints_;

}
int NPCObject::getHitChance() const {
    return hitChance_;
}

void NPCObject::setState(CharacterState* newState) {
    if (this->characterState_ != nullptr){
        delete characterState_;
    }
    this->characterState_ = newState;
}

CharacterState* NPCObject::getCurrentState() const {
    return this->characterState_;
}

CharacterState* NPCObject::getPreviousState() const {
    return this->characterState_;
}


std::pair<int, int> NPCObject::getPosition() const {

    // It gives an error if you compile with older c++ standard
    std::pair<int, int> position = {positionX_, positionY_};
    return position;
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
