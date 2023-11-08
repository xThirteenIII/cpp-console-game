#include "Menu.h"
#include "../GameManager.h"
#include <cstddef>
#include <curses.h>
#include <string>
#include <vector>
#ifndef _WIN32
#include <ncurses.h>
#endif

Menu::Menu(std::vector<std::string> items):items(items), selectedItem(0){}

void Menu::display() const{
    for (size_t i=0; i < items.size(); i++){
        if (static_cast<int>(i) == this->selectedItem){
            // Highlight selected item
            // TODO: create a method in NcursesAdapter that handles this mvprintw
            mvprintw(i, 0, ">> %s", items[i].c_str());
        } else {
            mvprintw(i, 0, "   %s", items[i].c_str());
        }
    }
}

void Menu::getSelection(){
    
    MapHandler& mapHandler = GameManager::GetInstance()->getMapHandler();

    int pressedKey = mapHandler.getRenderer()->handleInput();

    if (pressedKey != ERR){
        switch (pressedKey) {
            case KEY_UP:
                if (selectedItem > 0){
                    selectedItem-=1;
                }
                break;
            case KEY_DOWN:
                if (selectedItem < static_cast<int>(this->items.size())-1){
                    selectedItem+=1;
                }
        
            default:
                break;
        }
    }
}
