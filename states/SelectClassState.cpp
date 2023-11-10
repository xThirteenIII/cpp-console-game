#include "SelectClassState.h"
#include "MainMenuState.h"
#include "../ui/SelectClassMenu.h"
#include "../GameManager.h"
#include "../characters/AbstractEntityFactory.h"
#include "../characters/PhilosopherFactory.h"
#include "../characters/EngineerFactory.h"
#include "Context.h"
#include "GameOverState.h"
#include "GameRunningState.h"
#include "GameState.h"
#include "QuitGameState.h"
#include <iostream>
#include <string>
#include <vector>

SelectClassState::SelectClassState(){

    CreateMenu* classMenu = new SelectClassMenu();
    menu_ = classMenu->createMenu();
}

void SelectClassState::enter(){
    menu_->display();
}

void SelectClassState::update(Context* context){
    // Handle main menu logic
    // 
    int selectedItem = menu_->getSelected();

    if (GameManager::GetInstance()->getInputKey() != ERR){
        switch (GameManager::GetInstance()->getInputKey()) {
            case '\n':
                if (selectedItem == 0){

                    // Create Warrior player
                    EntityFactory* engineerFactory = new EngineerFactory();
                    GameManager::GetInstance()->setPlayer(engineerFactory->createCharacter());
                    GameManager::GetInstance()->setNPC(engineerFactory->createEnemy());
                    context->setState(new GameRunningState());
                }else if (selectedItem == 1){

                    // Create Wizard player
                    EntityFactory* philosopherFactory = new PhilosopherFactory();
                    GameManager::GetInstance()->setPlayer(philosopherFactory->createCharacter());
                    GameManager::GetInstance()->setNPC(philosopherFactory->createEnemy());
                    context->setState(new GameRunningState());
                }
                break;
            default:
                break;
        }
    }

    // Initialize map before starting the game
    GameManager::GetInstance()->getMapHandler()->initializeMap();
}

void SelectClassState::exit(){
}
