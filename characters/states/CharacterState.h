#ifndef _CHARACTERSTATE_H_
#define _CHARACTERSTATE_H_

#include "../factory/AbstractEntity.h"

class Character;

class CharacterState{
    public:
        virtual void enter() = 0;
        virtual void update(Character* character) = 0;
        virtual void exit() = 0;
};
#endif

