#ifndef _COMBATMENU_H_
#define _COMBATMENU_H_
#include "AbstractMenu.h"
#include "CreateMenu.h"

class CombatMenu: public CreateMenu{
    public:
        AbstractMenu* createMenu() override;

};
#endif
