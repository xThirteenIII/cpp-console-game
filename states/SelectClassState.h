#ifndef _SELECTCLASSSTATE_H_
#define _SELECTCLASSSTATE_H_
#include "GameState.h"
#include "../ui/Menu.h"

class SelectClassState: public GameState{
    private:
        Menu* classMenu;

    public:
        SelectClassState();
        void enter() override;
        void update(Context* context) override;
        void exit() override;

};

#endif
