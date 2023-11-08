#ifndef _MENU_H_
#define _MENU_H_

#include <string>
#include <vector>
class Menu{
    private:
        std::vector<std::string> items;
        int selectedItem;

    public:
        Menu(std::vector<std::string> items);

        int getSelection();

        void display() const;
};
#endif
