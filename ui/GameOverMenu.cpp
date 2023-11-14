#include "GameOverMenu.h"
#include "AbstractMenu.h"
#include "MenuItems.h"
#include <string>
#include <vector>

AbstractMenu* GameOverMenu::createMenu(){

    // Ignore error due to older c++ standard
    std::vector<std::string> items = {"Retry", "Quit Game"};
    return new MenuItems(items);
}
