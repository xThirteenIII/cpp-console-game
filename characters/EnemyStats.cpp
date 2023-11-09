#include "EnemyStats.h"
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

