#ifndef _NPCOBJECT_H_
#define _NPCOBJECT_H_
#include "AbstractEntity.h"
#include "../states/CharacterState.h"
#include "../../combat/Attack.h"
#include <utility>
#include <vector>

class NPCObject : public AbstractEntity{
    private:
        int healthPoints_;
        int armorPoints_;
        int positionX_; 
        int positionY_; 
        std::vector<Attack*> attacks_;
        Attack* currentAttack_;
        CharacterState* characterState_;

    public:
        NPCObject(int health, int armor, int attack, int precision, int x, int y);
        int getHealthPoints() const override;
        int getArmorPoints() const override;
        Attack* getCurrentAttack() const override;
        void setAttackType(AttackType type) override;
        void addAttack(Attack* attack) override;
        void setState(CharacterState* newState) override;
        CharacterState* getCurrentState() const override;
        CharacterState* getPreviousState() const override;
        std::pair<int, int> getPosition() const override;

        void takeDamage(int damage) override;
        void performAttack(AbstractEntity* entity) override;
        void move(int deltaX, int deltaY) override;
        bool isAlive() const override;
};
#endif
