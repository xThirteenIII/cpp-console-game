#ifndef _GAMEOVERMENU_H_
#define _GAMEOVERMENU_H_
#include "AbstractMenu.h"
#include "CreateMenu.h"

class GameOverMenu: public CreateMenu{
    public:
        AbstractMenu* createMenu() override;

};
#endif
