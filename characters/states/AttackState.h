#ifndef _ATTACKSTATE_H
#define _ATTACKSTATE_H
#include "CharacterState.h"
#include "../factory/AbstractEntity.h"

class AttackState: public CharacterState{
    void enter() override;
    void update() override;
    void exit() override;
};
#endif
