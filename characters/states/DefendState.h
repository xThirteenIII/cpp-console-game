#ifndef _DEFENDSTATE_H_
#define _DEFENDSTATE_H_
#include "CharacterState.h"

class DefendState: public CharacterState{
    void enter() override;
    void update(Character* character) override;
    void exit() override;
};
#endif
