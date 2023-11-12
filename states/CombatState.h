#ifndef _COMBATSTATE_H_
#define _COMBATSTATE_H_

#include "GameState.h"
#include "../ui/AbstractMenu.h"

class CombatState : public GameState{
    private:
        AbstractMenu* menu_;
    public:
        CombatState();
        void enter() override;
        void update(Context* context) override;
        void exit() override;
};

#endif
