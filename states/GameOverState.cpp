#include "GameOverState.h"
#include "MainMenuState.h"
#include "../ui/GameOverMenu.h"
#include "../ui/MainMenu.h"
#include "../GameManager.h"
#include "Context.h"
#include "GameOverState.h"
#include "GameRunningState.h"
#include "GameState.h"
#include "QuitGameState.h"
#include <iostream>
#include <string>
#include <vector>


GameOverState::GameOverState(){
    CreateMenu* gameOverMenu = new GameOverMenu();
    menu_ = gameOverMenu->createMenu();

}

void GameOverState::enter(){
    menu_->display();
}
void GameOverState::update(Context* context){
    // Handle main menu logic
    // 
    int selectedItem = menu_->getSelected();

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
