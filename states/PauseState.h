#ifndef _PAUSESTATE_H_
#define _PAUSESTATE_H_

#include "GameState.h"
class PauseState : public GameState { 

    public:
        void enter() override;    
        void update() override;    
        void exit() override;    
};

#endif
