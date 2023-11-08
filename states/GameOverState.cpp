#include "GameOverState.h"
#include <iostream>


GameOverState::GameOverState():gameOverMenu(nullptr){
    // If it gives an error is due to using an old c++ std version
    // Just specify std=c++20 when compiling
    std::vector<std::string> menuItems{"Retry", "Main Menu"};
    gameOverMenu = new Menu(menuItems);

}

void GameOverState::enter(){
    gameOverMenu->display();
}
void GameOverState::update(Context* context){
    gameOverMenu->getSelection();
}
void GameOverState::exit(){
}
