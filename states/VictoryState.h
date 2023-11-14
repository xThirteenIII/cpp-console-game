#ifndef _VICTORYSTATE_H_
#define _VICTORYSTATE_H_

#include "GameState.h"
#include "../ui/AbstractMenu.h"

class VictoryState : public GameState{
    private:
        AbstractMenu* menu_;
    public:
        VictoryState();
        void enter() override;
        void update(Context* context) override;
        void exit() override;
};

#endif
