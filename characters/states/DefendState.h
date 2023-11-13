#ifndef _DEFENDSTATE_H_
#define _DEFENDSTATE_H_
#include "CharacterState.h"
#include "../factory/AbstractEntity.h"

class DefendState: public CharacterState{
    void enter() override;
    void update() override;
    void exit() override;
};
#endif
