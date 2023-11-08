#include "PauseState.h"
#include <iostream>

PauseState::PauseState():pauseMenu(nullptr){
    // If it gives an error is due to using an old c++ std version
    // Just specify std=c++20 when compiling
    std::vector<std::string> menuItems{"Resume", "Main Menu"};
    pauseMenu = new Menu(menuItems);

}

void PauseState::enter() {
    pauseMenu->display();
}
void PauseState::update(Context* context) {
    pauseMenu->getSelection();
}
void PauseState::exit() {
}
