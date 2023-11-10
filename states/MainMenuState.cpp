#include "MainMenuState.h"
#include "../ui/MainMenu.h"
#include "../GameManager.h"
#include "Context.h"
#include "SelectClassState.h"
#include "GameOverState.h"
#include "GameRunningState.h"
#include "GameState.h"
#include "QuitGameState.h"
#include <iostream>
#include <string>
#include <vector>

MainMenuState::MainMenuState(){
    CreateMenu* mainMenu = new MainMenu();
    menu_ = mainMenu->createMenu();
}

void MainMenuState::enter(){
    menu_->display();
}

void MainMenuState::update(Context* context){
    // Handle main menu logic
    // 
    int selectedItem = menu_->getSelected();

    if (GameManager::GetInstance()->getInputKey() != ERR){
        switch (GameManager::GetInstance()->getInputKey()) {
            case '\n':
                if (selectedItem == 0){
                    context->setState(new SelectClassState());
                }else if (selectedItem == 1){
                    context->setState(new QuitGameState());
                }
                break;
            default:
                break;
        }
    }
}

void MainMenuState::exit(){
}
