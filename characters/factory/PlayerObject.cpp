#include "PlayerObject.h"
#include "../../GameManager.h"
#include <utility>

PlayerObject::PlayerObject(int health, int armor, int attack, int precision, int x, int y):
                healthPoints_(health),
                armorPoints_(armor),
                attackPoints_(attack),
                hitChance_(precision),
                positionX_(x),
                positionY_(y){

}


int PlayerObject::getHealthPoints() const {
    return healthPoints_;
}
int PlayerObject::getArmorPoints() const {
    return armorPoints_;
}
int PlayerObject::getAttackPoints() const {
    return attackPoints_;

}
int PlayerObject::getHitChance() const {
    return hitChance_;
}

void PlayerObject::setState(CharacterState* newState) {
    this->characterState_->setState(newState);
}


CharacterState* PlayerObject::getCurrentState() const {
    return this->characterState_->getCurrentState();
}

CharacterState* PlayerObject::getPreviousState() const {
    return this->characterState_->getPreviousState();
}

std::pair<int, int> PlayerObject::getPosition() const {
    // It gives an error if you compile with older c++ standard
    std::pair<int, int> position = {positionX_, positionY_};
    return position;
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
