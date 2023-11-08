#ifndef _GAMEOVERSTATE_H_
#define _GAMEOVERSTATE_H_

#include "GameState.h"
#include "../ui/Menu.h"

class GameOverState : public GameState{
    private:
        Menu* gameOverMenu;
    public:
        GameOverState();
        void enter() override;
        void update() override;
        void exit() override;
};

#endif

