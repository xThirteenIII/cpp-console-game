#include "CombatMenu.h"
#include "AbstractMenu.h"
#include "MenuItems.h"
#include <string>
#include <vector>

AbstractMenu* CombatMenu::createMenu(){

    // Ignore error due to older c++ standard
    std::vector<std::string> items = {"Base Attack","Special Attack"};
    return new MenuItems(items);
}
