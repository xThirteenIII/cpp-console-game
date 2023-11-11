#include "NPCObject.h"
#include "../../GameManager.h"
#include <utility>

NPCObject::NPCObject(int health, int armor, int attack, int precision, int x, int y):
                healthPoints_(health),
                armorPoints_(armor),
                attackPoints_(attack),
                hitChance_(precision),
                positionX_(x),
                positionY_(y){

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

std::pair<int, int> NPCObject::getPosition() const {

    // It gives an error if you compile with older c++ standard
    std::pair<int, int> position = {positionX_, positionY_};
    return position;
}

void NPCObject::move(int deltaX, int deltaY){

    int boundX = GameManager::GetInstance()->getSetting("W_HEIGHT") - 1;
    int boundY = GameManager::GetInstance()->getSetting("W_WIDTH") - 1;
    

   // If the new position is inside the map, move the entity
   if (((this->positionX_ + deltaX) < boundX && (this->positionX_ + deltaX) > 0) &&
       ((this->positionY_ + deltaY) < boundY && (this->positionY_ + deltaY) > 0)){

       this->positionX_ += deltaX; 
       this->positionY_ += deltaY;
   }

}
