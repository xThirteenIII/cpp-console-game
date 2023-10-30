#ifndef _GAMEOVERSTATE_H_
#define _GAMEOVERSTATE_H_

#include "GameState.h"
class GameOverState : public GameState{
    public:
        void enter() override;
        void update() override;
        void exit() override;
};

#endif

