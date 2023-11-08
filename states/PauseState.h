#ifndef _PAUSESTATE_H_
#define _PAUSESTATE_H_

#include "GameState.h"
#include "../ui/Menu.h"

class PauseState : public GameState { 
    private:
        Menu* pauseMenu;

    public:
        PauseState();
        void enter() override;    
        void update(Context* context) override;    
        void exit() override;    
};

#endif
