#ifndef _CREATEMENU_H_
#define _CREATEMENU_H_
#include "AbstractMenu.h"

class CreateMenu{
    public:
        // is the destructor necessary?
        // virtual ~EntityFactory() = default;
        virtual AbstractMenu* createMenu() = 0;
};

#endif
