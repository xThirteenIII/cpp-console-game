#ifndef _QUITGAMESTATE_H_
#define _QUITGAMESTATE_H_

#include "GameState.h"
class QuitGameState: public GameState{
    public:
        void enter() override;
        void update(Context* context) override;
        void exit() override;
};
#endif

