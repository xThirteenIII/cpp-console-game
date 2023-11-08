#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Character.h"

class Player: public Character {
    public:
        Player();
        Player(int x, int y);
        void move(int deltaX, int deltaY) override;
};

#endif
