#ifndef _MAINMENU_H_
#define _MAINMENU_H_
#include "AbstractMenu.h"
#include "CreateMenu.h"

class MainMenu: public CreateMenu{
    public:
        AbstractMenu* createMenu() override;

};
#endif
