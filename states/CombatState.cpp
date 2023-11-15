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
#include <thread>
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

    // Print stats starting from half of the height of the gameboy screen
    // Not cool but we deal with it like this for now
    mvprintw(GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_X")
            +(GameManager::GetInstance()->getSetting("W_HEIGHT")/2),
            GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_Y"),
            "--------------------");
    mvprintw(GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_X")
            +(GameManager::GetInstance()->getSetting("W_HEIGHT")/2)+1,
            GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_Y"),
            "Player:");
    mvprintw(GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_X")
            +(GameManager::GetInstance()->getSetting("W_HEIGHT")/2)+2,
            GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_Y"),
            ("HP: "+std::to_string(GameManager::GetInstance()->getPlayer()->getHealthPoints())).c_str());
    mvprintw(GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_X")
            +(GameManager::GetInstance()->getSetting("W_HEIGHT")/2)+3,
            GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_Y"),
            ("AP: "+std::to_string(GameManager::GetInstance()->getPlayer()->getCurrentAttack()->damage)).c_str());
    mvprintw(GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_X")
            +(GameManager::GetInstance()->getSetting("W_HEIGHT")/2)+4,
            GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_Y"),
            ("PR: "+std::to_string(GameManager::GetInstance()->getPlayer()->getCurrentAttack()->hitChance)).c_str());

    // Print Enemy Stats starting from the center of the gamboy screen
    mvprintw(GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_X")
            +(GameManager::GetInstance()->getSetting("W_HEIGHT")/2)+1,
            GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_Y")
            +(GameManager::GetInstance()->getSetting("W_WIDTH")/2),
            "| Enemy:");
    mvprintw(GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_X")
            +(GameManager::GetInstance()->getSetting("W_HEIGHT")/2)+2,
            GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_Y")
            +(GameManager::GetInstance()->getSetting("W_WIDTH")/2),
            ("| HP: "+std::to_string(GameManager::GetInstance()->getNPC()->getHealthPoints())).c_str());
    mvprintw(GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_X")
            +(GameManager::GetInstance()->getSetting("W_HEIGHT")/2)+3,
            GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_Y")
            +(GameManager::GetInstance()->getSetting("W_WIDTH")/2),
            ("| AP: "+std::to_string(GameManager::GetInstance()->getNPC()->getCurrentAttack()->damage)).c_str());
    mvprintw(GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_X")
            +(GameManager::GetInstance()->getSetting("W_HEIGHT")/2)+4,
            GameManager::GetInstance()->getSetting("GAMEBOYSCREEN_Y")
            +(GameManager::GetInstance()->getSetting("W_WIDTH")/2),
            ("| PR: "+std::to_string(GameManager::GetInstance()->getNPC()->getCurrentAttack()->hitChance)).c_str());


    // Call enter() method of the current character state
    GameManager::GetInstance()->getPlayer()->getCurrentState()->enter();
}

void CombatState::update(Context* context){

    AbstractEntity* player = GameManager::GetInstance()->getPlayer();
    AbstractEntity* enemyNPC = GameManager::GetInstance()->getNPC();
    //Default attack is BASIC for enemy
    enemyNPC->setAttackType(AttackType::BASIC);

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
                        // Wait for a short duration (e.g., 1 second)
                        // not optimal but for now is ok

                    }else if (selectedItem == 1){

                        // This doesn't seem to work. Why?
                        player->addAttack(new Attack(AttackType::SPECIAL, 8, 85));
                        player->setAttackType(AttackType::SPECIAL);
                        player->performAttack(enemyNPC);
                    // User selected special attack
                    }

                    break;
                default:
                    break;
            }
        }
    }else{
        enemyNPC->performAttack(player);
    }

    GameManager::GetInstance()->getPlayer()->getCurrentState()->update();
}

void CombatState::exit(){
    GameManager::GetInstance()->getPlayer()->getCurrentState()->exit();
}
