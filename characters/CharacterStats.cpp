#include "CharacterStats.h"
#include <utility>

CharacterStats::CharacterStats(int health, int armor, int attack, int precision, int x, int y):
                healthPoints_(health),
                armorPoints_(armor),
                attackPoints_(attack),
                hitChance_(precision),
                positionX_(x),
                positionY_(y){

}


int CharacterStats::getHealthPoints() const {
    return healthPoints_;
}
int CharacterStats::getArmorPoints() const {
    return armorPoints_;
}
int CharacterStats::getAttackPoints() const {
    return attackPoints_;

}
int CharacterStats::getHitChance() const {
    return hitChance_;
}

std::pair<int, int> CharacterStats::getPosition() const {
    // It gives an error if you compile with older c++ standard
    std::pair<int, int> position = {positionX_, positionY_};
    return position;
}

