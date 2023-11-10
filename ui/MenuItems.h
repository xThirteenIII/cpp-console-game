#ifndef _MENUITEMS_H_
#define _MENUITEMS_H_
#include "AbstractMenu.h"
#include <utility>
#include <vector>

class MenuItems : public AbstractMenu{
    private:
        std::vector<std::string> items_;
        int selectedItem_;

    public:
        MenuItems(std::vector<std::string> items);
        virtual std::vector<std::string> getItems() const;
        virtual int getSelected();
        virtual void display() const;
};

#endif
