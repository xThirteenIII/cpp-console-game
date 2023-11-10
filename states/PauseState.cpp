#include "MainMenuState.h"
#include "../ui/PauseMenu.h"
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

PauseState::PauseState(){
    CreateMenu* pauseMenu = new PauseMenu();
    menu_ = pauseMenu->createMenu();
}

void PauseState::enter() {
    menu_->display();
}
void PauseState::update(Context* context) {
    // Handle main menu logic
    // 
    int selectedItem = menu_->getSelected();

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
