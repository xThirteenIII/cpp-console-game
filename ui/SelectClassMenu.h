#ifndef _SELECTCLASSMENU_H_
#define _SELECTCLASSMENU_H_
#include "AbstractMenu.h"
#include "CreateMenu.h"

class SelectClassMenu: public CreateMenu{
    public:
        AbstractMenu* createMenu() override;

};
#endif
