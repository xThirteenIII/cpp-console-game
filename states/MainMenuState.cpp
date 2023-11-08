#include "MainMenuState.h"
#include "../ui/Menu.h"
#include "../GameManager.h"
#include "Context.h"
#include "GameOverState.h"
#include "GameRunningState.h"
#include "GameState.h"
#include "QuitGameState.h"
#include <iostream>
#include <string>
#include <vector>

MainMenuState::MainMenuState():mainMenu(nullptr){

    // If it gives an error is due to using an old c++ std version
    std::vector<std::string> menuItems{"Start Game", "Quit Game"};

    // Need to do this because it gives errors if i try to initialize
    // after declaration!
    //menuItems.push_back("Start Game");
    //menuItems.push_back("Quit Game");

    mainMenu = new Menu(menuItems);
}

void MainMenuState::enter(){
    mainMenu->display();
}

void MainMenuState::update(Context* context){
    // Handle main menu logic
    // 
    int selectedItem = mainMenu->getSelection();

    if (GameManager::GetInstance()->getInputKey() != ERR){
        switch (GameManager::GetInstance()->getInputKey()) {
            case '\n':
                if (selectedItem == 0){
                    context->setState(new GameRunningState());
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
