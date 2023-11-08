#ifndef _MAINMENUSTATE_H_
#define _MAINMENUSTATE_H_

#include "GameState.h"
#include "../ui/Menu.h"
#include <vector>

class MainMenuState: public GameState{
    private:
        Menu* mainMenu;
    public:
        MainMenuState();
        void enter() override;
        void update(Context* context) override;
        void exit() override;
};

#endif

