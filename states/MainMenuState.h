#ifndef _MAINMENUSTATE_H_
#define _MAINMENUSTATE_H_

#include "GameState.h"
#include "../ui/AbstractMenu.h"
#include "../ui/CreateMenu.h"
#include <vector>


class MainMenuState: public GameState{
        AbstractMenu* menu_;
    public:
        // Should i have a default destructor that overrides the virtual one of GameState?
        MainMenuState();
        void enter() override;
        void update(Context* context) override;
        void exit() override;
};

#endif

