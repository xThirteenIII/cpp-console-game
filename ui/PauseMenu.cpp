#include "PauseMenu.h"
#include "AbstractMenu.h"
#include "MenuItems.h"
#include <string>
#include <vector>

AbstractMenu* PauseMenu::createMenu(){

    // Ignore error due to older c++ standard
    std::vector<std::string> items = {"Resume", "Main Menu"};
    return new MenuItems(items);
}
