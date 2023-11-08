#ifndef _GAMERUNNINGSTATE_H_
#define _GAMERUNNINGSTATE_H_

#include "GameState.h"

class GameRunningState : public GameState{

    public:
        void enter() override;
        void update(Context* context) override;
        void exit() override;
};

#endif

