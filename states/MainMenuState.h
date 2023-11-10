#ifndef _MAINMENUSTATE_H_
#define _MAINMENUSTATE_H_

#include "GameState.h"
#include "../ui/AbstractMenu.h"
#include "../ui/CreateMenu.h"
#include <vector>


class MainMenuState: public GameState{
        AbstractMenu* menu_;
    public:
        MainMenuState();
        void enter() override;
        void update(Context* context) override;
        void exit() override;
};

#endif

