#include "GameOverState.h"
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
    // Handle main menu logic
    // 
    int selectedItem = gameOverMenu->getSelection();

    if (GameManager::GetInstance()->getInputKey() != ERR){
        switch (GameManager::GetInstance()->getInputKey()) {
            case '\n':
                if (selectedItem == 0){
                    // TODO: Game Has to reset, this is not correct
                    context->setState(new GameRunningState());
                }else if (selectedItem == 1){

                    // Reset game and go to main menu
                    GameManager::GetInstance()->resetGame(); 
                    context->setState(new MainMenuState());
                }
                break;
            default:
                break;
        }
    }
}
void GameOverState::exit(){
}
