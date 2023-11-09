#ifndef _CHARACTERSTATS_H_
#define _CHARACTERSTATS_H_
#include "AbstractEntityStats.h"
#include <utility>

class CharacterStats : public AbstractEntityStats{
    private:
        int healthPoints_;
        int armorPoints_;
        int attackPoints_;
        int hitChance_;
        int positionX_; 
        int positionY_; 

    public:
        CharacterStats(int health, int armor, int attack, int precision, int x, int y);
        int getHealthPoints() const override;
        int getArmorPoints() const override;
        int getAttackPoints() const override;
        int getHitChance() const override;
        std::pair<int, int> getPosition() const override;
    
    
};

#endif
