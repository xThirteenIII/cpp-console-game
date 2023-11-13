#ifndef _NPCOBJECT_H_
#define _NPCOBJECT_H_
#include "AbstractEntity.h"
#include "../states/CharacterState.h"
#include "../../combat/Attack.h"
#include <utility>

class NPCObject : public AbstractEntity{
    private:
        int healthPoints_;
        int armorPoints_;
        int positionX_; 
        int positionY_; 
        Attack* attack;
        CharacterState* characterState_;

    public:
        NPCObject(int health, int armor, int attack, int precision, int x, int y);
        int getHealthPoints() const override;
        int getArmorPoints() const override;
        Attack* getCurrentAttack() const override;
        void setAttackType(AttackType type) override;
        void addAttack(const Attack* attack) override;
        void setState(CharacterState* newState) override;
        CharacterState* getCurrentState() const override;
        CharacterState* getPreviousState() const override;
        std::pair<int, int> getPosition() const override;
        void move(int deltaX, int deltaY) override;
        bool isAlive() const override;
};
#endif
