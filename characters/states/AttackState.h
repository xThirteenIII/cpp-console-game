#ifndef _ATTACKSTATE_H
#define _ATTACKSTATE_H
#include "CharacterState.h"

class AttackState: public CharacterState{
    void enter() override;
    void update(Character* character) override;
    void exit() override;
};
#endif
