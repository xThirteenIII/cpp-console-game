#ifndef _ENEMYSTATS_H_
#define _ENEMYSTATS_H_
#include "AbstractEntityStats.h"
#include <utility>

class EnemyStats : public AbstractEntityStats{
    private:
        int healthPoints_;
        int armorPoints_;
        int attackPoints_;
        int hitChance_;
        int positionX_; 
        int positionY_; 

    public:
        EnemyStats(int health, int armor, int attack, int precision, int x, int y);
        int getHealthPoints() const override;
        int getArmorPoints() const override;
        int getAttackPoints() const override;
        int getHitChance() const override;
        std::pair<int, int> getPosition() const override;
    
    
};

#endif
