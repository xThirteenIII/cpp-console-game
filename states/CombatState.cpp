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
    if (GameManager::GetInstance()->getCurrentTurn() % 2 == 0){
        GameManager::GetInstance()->getPlayer()->setState(new AttackState());
        GameManager::GetInstance()->getNPC()->setState(new DefendState());
    }else{
        GameManager::GetInstance()->getPlayer()->setState(new DefendState());
        GameManager::GetInstance()->getNPC()->setState(new AttackState());
    }

    // If we enter combat state and player is attacking, display menu
    if (dynamic_cast<AttackState*>(GameManager::GetInstance()->getPlayer()->getCurrentState())){
            menu_->display();
        }

    // Call enter() method of the current character state
    GameManager::GetInstance()->getPlayer()->getCurrentState()->enter();
}

void CombatState::update(Context* context){

    AbstractEntity* player = GameManager::GetInstance()->getPlayer();
    AbstractEntity* enemyNPC = GameManager::GetInstance()->getNPC();

    if (!(player->isAlive())){

        // Player is KO
        context->setState(new GameOverState());
        return;
    }else if (!(enemyNPC->isAlive())){
        
        // For now, kill the enemy and win.
        // Player has defeated the enemy, return to map
        context->setState(new VictoryState());
        return;
    }

    // Here it's run a combat loop, which ends only when either the player
    // defeats the enemy or the player loses all HP.
    int selectedItem = menu_->getSelected();

    if (dynamic_cast<AttackState*>(player->getCurrentState())){
        if (GameManager::GetInstance()->getInputKey() != ERR){
            switch (GameManager::GetInstance()->getInputKey()) {
                case '\n':

                    // User selected base attack
                    if (selectedItem == 0){
                        player->setAttackType(AttackType::BASIC);
                        player->performAttack(enemyNPC);

                    }else if (selectedItem == 1){
                        player->setAttackType(AttackType::SPECIAL);
                        player->performAttack(enemyNPC);
                    // User selected special attack
                    }
                    break;
                default:
                    break;
            }
        }
    }

    GameManager::GetInstance()->getPlayer()->getCurrentState()->update();
}

void CombatState::exit(){
    GameManager::GetInstance()->toNextTurn();
    GameManager::GetInstance()->getPlayer()->getCurrentState()->exit();
}
