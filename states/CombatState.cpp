#include "CombatState.h"
#include "MainMenuState.h"
#include "VictoryState.h"
#include "../ui/CombatMenu.h"
#include "../ui/MainMenu.h"
#include "../GameManager.h"
#include "../characters/states/AttackState.h"
#include "../characters/states/IdleState.h"
#include "../characters/states/DefendState.h"
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

    // Set player state to Attacking
    // Might want to handle character states within the update() method in character/states/
    GameManager::GetInstance()->getPlayer()->setState(new AttackState());
    GameManager::GetInstance()->getNPC()->setState(new DefendState());

    // If we enter combat state, display menu
    menu_->display();
}

void CombatState::update(Context* context){

    if (GameManager::GetInstance()->getPlayer()->)<=0){

        // Player is KO
        context->setState(new GameOverState());
        return;
    }else if (GameManager::GetInstance()->getNPC()->getHealthPoints()<=0){
        
        // For now, kill the enemy and win.
        // Player has defeated the enemy, return to map
        context->setState(new PlayerWinsState());
        return;
    }

    // Here it's run a combat loop, which ends only when either the player
    // defeats the enemy or the player loses all HP.
    int selectedItem = menu_->getSelected();


    if (GameManager::GetInstance()->getInputKey() != ERR){
        switch (GameManager::GetInstance()->getInputKey()) {
            case '\n':

                // User selected base attack
                if (selectedItem == 0){
                    GameManager::GetInstance()->getPlayer()->
                    
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
