#ifndef _GAMEOVERSTATE_H_
#define _GAMEOVERSTATE_H_

#include "GameState.h"
#include "../ui/AbstractMenu.h"

class GameOverState : public GameState{
    private:
        AbstractMenu* menu_;
    public:
        GameOverState();
        void enter() override;
        void update(Context* context) override;
        void exit() override;
};

#endif

