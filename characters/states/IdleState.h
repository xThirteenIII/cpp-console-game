#ifndef _IDLESTATE_H_
#define _IDLESTATE_H_
#include "../factory/AbstractEntity.h"
#include "CharacterState.h"

class IdleState: public CharacterState{
    void enter() override;
    void update() override;
    void exit() override;
};
#endif
