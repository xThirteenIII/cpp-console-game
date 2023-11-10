#ifndef _SELECTCLASSSTATE_H_
#define _SELECTCLASSSTATE_H_
#include "GameState.h"
#include "../ui/AbstractMenu.h"

class SelectClassState: public GameState{
    private:
        AbstractMenu* menu_;
    public:
        SelectClassState();
        void enter() override;
        void update(Context* context) override;
        void exit() override;

};

#endif
