#ifndef _VICTORYSTATE_H_
#define _VICTORYSTATE_H_

#include "GameState.h"
class VictoryState : public GameState{
    public:
        VictoryState();
        void enter() override;
        void update(Context* context) override;
        void exit() override;
};

#endif
