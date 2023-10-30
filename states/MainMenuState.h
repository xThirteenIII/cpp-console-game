#ifndef _MAINMENUSTATE_H_
#define _MAINMENUSTATE_H_

#include "GameState.h"
class MainMenuState: public GameState{
    public:
        void enter() override;
        void update() override;
        void exit() override;
};

#endif

