#ifndef _PAUSEMENU_H_
#define _PAUSEMENU_H_
#include "AbstractMenu.h"
#include "CreateMenu.h"

class PauseMenu: public CreateMenu{
    public:
        AbstractMenu* createMenu() override;

};
#endif
