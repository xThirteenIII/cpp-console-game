#include "VictoryState.h"
#include "CombatState.h"
#include "../GameManager.h"

#include "../ui/CreateMenu.h"
#include "../ui/VictoryMenu.h"
#include "MainMenuState.h"
#include "QuitGameState.h"
#include <string>
#ifndef _WIN32
#include <ncurses.h>
#endif

VictoryState::VictoryState(){
    CreateMenu* classMenu = new VictoryMenu();
    menu_ = classMenu->createMenu();
    // Print menu options to go to Main Menu or Quit Game
}

void VictoryState::enter(){
    // IMPORTANT: mvprintw overrides previous calls so order is important
    mvprintw(0,0,"%s", GameManager::GetInstance()->getGameBoyArt());
    this->menu_->display();
    
    // Print you won in middle of screen, bottom HALF
    // NOTE: gameboyscreen_x indicates the row -> counter intuitively is the height not the width
    mvprintw(GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_X")+(GameManager::GetInstance()->getSetting("W_HEIGHT")/2),GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_Y")+(GameManager::GetInstance()->getSetting("W_WIDTH")-(std::string("YOU WON").size()/2))/2, "YOU WON");

}
void VictoryState::update(Context* context){

    // Here it's run a combat loop, which ends only when either the player
    // defeats the enemy or the player loses all HP.
    int selectedItem = menu_->getSelected();

    if (GameManager::GetInstance()->getInputKey() != ERR){
        switch (GameManager::GetInstance()->getInputKey()) {
            case '\n':

                // User selected Main Menu
                if (selectedItem == 0){
                    // Where is more correct to reset the game?
                    GameManager::GetInstance()->resetGame(); 
                    context->setState(new MainMenuState());
                }else if (selectedItem == 1){
                // User selected Quit Game
                    context->setState(new QuitGameState());
                }
                break;
            default:
                break;
        }
    }
}
void VictoryState::exit(){

}
