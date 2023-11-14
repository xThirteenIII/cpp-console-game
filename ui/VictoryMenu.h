#ifndef _VICTORYMENU_H_
#define _VICTORYMENU_H_
#include "AbstractMenu.h"
#include "CreateMenu.h"

class VictoryMenu: public CreateMenu{
    public:
        AbstractMenu* createMenu() override;

};
#endif
