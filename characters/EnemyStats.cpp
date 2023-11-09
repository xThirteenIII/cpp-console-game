#include "EnemyStats.h"
#include "../GameManager.h"
#include <utility>

EnemyStats::EnemyStats(int health, int armor, int attack, int precision, int x, int y):
                healthPoints_(health),
                armorPoints_(armor),
                attackPoints_(attack),
                hitChance_(precision),
                positionX_(x),
                positionY_(y){

}


int EnemyStats::getHealthPoints() const {
    return healthPoints_;
}
int EnemyStats::getArmorPoints() const {
    return armorPoints_;
}
int EnemyStats::getAttackPoints() const {
    return attackPoints_;

}
int EnemyStats::getHitChance() const {
    return hitChance_;
}

std::pair<int, int> EnemyStats::getPosition() const {
    // It gives an error if you compile with older c++ standard
    std::pair<int, int> position = {positionX_, positionY_};
    return position;
}

void EnemyStats::move(int deltaX, int deltaY){

    int boundX = GameManager::GetInstance()->getSetting("W_HEIGHT") - 1;
    int boundY = GameManager::GetInstance()->getSetting("W_WIDTH") - 1;
    

   // If the new position is inside the map, move the entity
   if (((this->positionX_ + deltaX) < boundX && (this->positionX_ + deltaX) > 0) &&
       ((this->positionY_ + deltaY) < boundY && (this->positionY_ + deltaY) > 0)){

       this->positionX_ += deltaX; 
       this->positionY_ += deltaY;
   }

}
