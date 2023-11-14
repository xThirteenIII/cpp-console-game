#ifndef _PLAYEROBJECT_H_
#define _PLAYEROBJECT_H_
#include "AbstractEntity.h"
#include "../states/CharacterState.h"
#include <utility>
#include <vector>

class PlayerObject : public AbstractEntity{
    private:
        int healthPoints_;
        int armorPoints_;
        int positionX_; 
        int positionY_; 
        std::vector<Attack*> attacks_;
        Attack* currentAttack_;
        CharacterState* characterState_;

    public:
        PlayerObject(int health, int armor, int attack, int precision, int x, int y);
        int getHealthPoints() const override;
        int getArmorPoints() const override;
        Attack* getCurrentAttack() const override;
        void setAttackType(AttackType type) override;
        void addAttack(Attack* attack) override;
        CharacterState* getCurrentState() const override;
        CharacterState* getPreviousState() const override;
        std::pair<int, int> getPosition() const override;
        void setState(CharacterState* newState) override;
        void takeDamage(int damage) override;
        void performAttack(AbstractEntity* entity) override;
        void move(int deltaX, int deltaY) override;
        bool isAlive() const override;
    
    
};

#endif
