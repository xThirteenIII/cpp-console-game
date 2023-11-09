#ifndef _NPCSTATS_H_
#define _NPCSTATS_H_
#include "AbstractEntity.h"
#include <utility>

class NPCStats : public AbstractEntity{
    private:
        int healthPoints_;
        int armorPoints_;
        int attackPoints_;
        int hitChance_;
        int positionX_; 
        int positionY_; 

    public:
        NPCStats(int health, int armor, int attack, int precision, int x, int y);
        int getHealthPoints() const override;
        int getArmorPoints() const override;
        int getAttackPoints() const override;
        int getHitChance() const override;
        std::pair<int, int> getPosition() const override;
        void move(int deltaX, int deltaY) override;
    
    
};

#endif
