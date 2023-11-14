#include "VictoryMenu.h"
#include "AbstractMenu.h"
#include "MenuItems.h"
#include <string>
#include <vector>

AbstractMenu* VictoryMenu::createMenu(){

    // Ignore error due to older c++ standard
    std::vector<std::string> items = {"Main Menu","Quit Game"};
    return new MenuItems(items);
}
