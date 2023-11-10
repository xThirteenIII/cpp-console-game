#include "MainMenu.h"
#include "AbstractMenu.h"
#include "MenuItems.h"
#include <string>
#include <vector>

AbstractMenu* MainMenu::createMenu(){

    // Ignore error due to older c++ standard
    std::vector<std::string> items = {"Start Game","Quit Game"};
    return new MenuItems(items);
}
