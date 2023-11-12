#ifndef _NPCOBJECT_H_
#define _NPCOBJECT_H_
#include "AbstractEntity.h"
#include "../states/CharacterState.h"
#include "../states/Character.h"
#include <utility>

class NPCObject : public AbstractEntity{
    private:
        int healthPoints_;
        int armorPoints_;
        int attackPoints_;
        int hitChance_;
        int positionX_; 
        int positionY_; 
        Character* characterState_;

    public:
        NPCObject(int health, int armor, int attack, int precision, int x, int y);
        int getHealthPoints() const override;
        int getArmorPoints() const override;
        int getAttackPoints() const override;
        int getHitChance() const override;
        CharacterState* getCurrentState() const override;
        CharacterState* getPreviousState() const override;
        void setState(CharacterState* newState) override;
        std::pair<int, int> getPosition() const override;
        void move(int deltaX, int deltaY) override;
    
    
};

#endif
