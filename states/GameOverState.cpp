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

    // Print you won in middle of screen, bottom HALF
    // NOTE: gameboyscreen_x indicates the row -> counter intuitively is the height not the width
    mvprintw(GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_X")+(GameManager::GetInstance()->getSetting("W_HEIGHT")/2),
            GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_Y")+(GameManager::GetInstance()->getSetting("W_WIDTH")-(std::string("YOU LOST").size()))/2,
            "YOU LOST");
}
void GameOverState::update(Context* context){
    // Handle main menu logic
    // 
    int selectedItem = menu_->getSelected();

    if (GameManager::GetInstance()->getInputKey() != ERR){
        switch (GameManager::GetInstance()->getInputKey()) {
            case '\n':

                // Player selected "Retry"
                if (selectedItem == 0){
                    // TODO: Game Has to reset, this is not correct
                    GameManager::GetInstance()->resetGame(); 
                    context->setState(new MainMenuState());
                }else if (selectedItem == 1){

                    // Player selected "Quit Game"
                    context->setState(new QuitGameState());
                    break;
                }
            default:
                break;
        }
    }
}
void GameOverState::exit(){
}
