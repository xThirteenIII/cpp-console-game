#include "SelectClassMenu.h"
#include "AbstractMenu.h"
#include "MenuItems.h"
#include <string>
#include <vector>

AbstractMenu* SelectClassMenu::createMenu(){

    // Ignore error due to older c++ standard
    std::vector<std::string> items = {"Engineer", "Philosopher"};
    return new MenuItems(items);
}
