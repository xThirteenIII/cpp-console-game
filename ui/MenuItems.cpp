#include "MenuItems.h"
#include "../GameManager.h"
#include <string>
#include <vector>

#ifndef _WIN32
#include <ncurses.h>
#endif

MenuItems::MenuItems(std::vector<std::string> items){
    this->items_ = items;

    // Default selected item is the first one of the menu
    this->selectedItem_ = 0;
}

std::vector<std::string> MenuItems::getItems() const{
    return this->items_;
}

int MenuItems::getSelected(){
    if (GameManager::GetInstance()->getInputKey() != ERR){
        switch (GameManager::GetInstance()->getInputKey()) {
            case KEY_UP:
                if (selectedItem_ > 0){
                    selectedItem_-=1;
                }
                break;
            case KEY_DOWN:
                if (selectedItem_ < static_cast<int>(this->items_.size())-1){
                    selectedItem_+=1;
                }
                break;
            default:
                break;
        }
    }
    return selectedItem_;
}

void MenuItems::display() const{
    for (size_t i=0; i < items_.size(); i++){
        if (static_cast<int>(i) == this->selectedItem_){
            // Highlight selected item
            // TODO: create a method in NcursesAdapter that handles this mvprintw
            mvprintw(i, 0, ">> %s", items_[i].c_str());
        } else {
            mvprintw(i, 0, "   %s", items_[i].c_str());
        }
    }
    
}
