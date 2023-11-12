#ifndef _IDLESTATE_H_
#define _IDLESTATE_H_
#include "CharacterState.h"

class IdleState: public CharacterState{
    void enter() override;
    void update(Character* character) override;
    void exit() override;
};
#endif
