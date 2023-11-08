#include "MainMenuState.h"
#include "../ui/Menu.h"
#include "../GameManager.h"
#include "Context.h"
#include "GameOverState.h"
#include "GameRunningState.h"
#include "GameState.h"
#include "QuitGameState.h"
#include "PauseState.h"
#include <iostream>
#include <string>
#include <vector>

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
    // Handle main menu logic
    // 
    int selectedItem = pauseMenu->getSelection();

    if (GameManager::GetInstance()->getInputKey() != ERR){
        switch (GameManager::GetInstance()->getInputKey()) {
            case '\n':
                if (selectedItem == 0){
                    context->setState(new GameRunningState());
                }else if (selectedItem == 1){
                    context->setState(new MainMenuState());
                }
                break;
            default:
                break;
        }
    }
}
void PauseState::exit() {
}
