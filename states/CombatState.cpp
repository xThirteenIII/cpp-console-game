#include "CombatState.h"
#include "MainMenuState.h"
#include "../ui/CombatMenu.h"
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


CombatState::CombatState(){
    CreateMenu* combatMenu = new CombatMenu();
    menu_ = combatMenu->createMenu();

}

void CombatState::enter(){
    menu_->display();
}
void CombatState::update(Context* context){
    // Handle main menu logic
    // 
    int selectedItem = menu_->getSelected();

    if (GameManager::GetInstance()->getInputKey() != ERR){
        switch (GameManager::GetInstance()->getInputKey()) {
            case '\n':

                // User selected base attack
                if (selectedItem == 0){
                    // TODO: Game Has to reset, this is not correct
                    context->setState(new GameRunningState());
                }else if (selectedItem == 1){
                // User selected special attack
                
                }
                break;
            default:
                break;
        }
    }
}
void CombatState::exit(){
}
