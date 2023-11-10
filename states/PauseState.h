#ifndef _PAUSESTATE_H_
#define _PAUSESTATE_H_

#include "GameState.h"
#include "../ui/AbstractMenu.h"

class PauseState : public GameState { 
        AbstractMenu* menu_;
    public:
        PauseState();
        void enter() override;    
        void update(Context* context) override;    
        void exit() override;    
};

#endif
