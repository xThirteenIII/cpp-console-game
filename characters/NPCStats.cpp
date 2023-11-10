#include "NPCStats.h"
#include "../GameManager.h"
#include <utility>

NPCStats::NPCStats(int health, int armor, int attack, int precision, int x, int y):
                healthPoints_(health),
                armorPoints_(armor),
                attackPoints_(attack),
                hitChance_(precision),
                positionX_(x),
                positionY_(y){

}


int NPCStats::getHealthPoints() const {
    return healthPoints_;
}
int NPCStats::getArmorPoints() const {
    return armorPoints_;
}
int NPCStats::getAttackPoints() const {
    return attackPoints_;

}
int NPCStats::getHitChance() const {
    return hitChance_;
}

std::pair<int, int> NPCStats::getPosition() const {

    // It gives an error if you compile with older c++ standard
    std::pair<int, int> position = {positionX_, positionY_};
    return position;
}

void NPCStats::move(int deltaX, int deltaY){

    int boundX = GameManager::GetInstance()->getSetting("W_HEIGHT") - 1;
    int boundY = GameManager::GetInstance()->getSetting("W_WIDTH") - 1;
    

   // If the new position is inside the map, move the entity
   if (((this->positionX_ + deltaX) < boundX && (this->positionX_ + deltaX) > 0) &&
       ((this->positionY_ + deltaY) < boundY && (this->positionY_ + deltaY) > 0)){

       this->positionX_ += deltaX; 
       this->positionY_ += deltaY;
   }

}
