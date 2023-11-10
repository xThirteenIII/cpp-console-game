#include "SelectClassState.h"
#include "MainMenuState.h"
#include "../ui/Menu.h"
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

SelectClassState::SelectClassState():classMenu(nullptr){

    // If it gives an error is due to using an old c++ std version
    std::vector<std::string> menuItems{"Engineer", "Philosopher"};

    // Need to do this because it gives errors if i try to initialize
    // after declaration!
    //menuItems.push_back("Start Game");
    //menuItems.push_back("Quit Game");

    classMenu = new Menu(menuItems);
}

void SelectClassState::enter(){
    classMenu->display();
}

void SelectClassState::update(Context* context){
    // Handle main menu logic
    // 
    int selectedItem = classMenu->getSelection();

    if (GameManager::GetInstance()->getInputKey() != ERR){
        switch (GameManager::GetInstance()->getInputKey()) {
            case '\n':
                if (selectedItem == 0){

                    // Create Warrior player
                    EntityFactory* engineerFactory = new EngineerFactory();
                    GameManager::GetInstance()->setPlayer(engineerFactory->createCharacter());
                    context->setState(new GameRunningState());
                }else if (selectedItem == 1){

                    // Create Wizard player
                    EntityFactory* philosopherFactory = new PhilosopherFactory();
                    GameManager::GetInstance()->setPlayer(philosopherFactory->createCharacter());
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
