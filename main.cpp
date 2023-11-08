#include "GameManager.h"
#include "states/Context.h"
#include "states/GameOverState.h"
#include "states/GameRunningState.h"
#include "globals.h"
#include "states/GameState.h"
#include "states/MainMenuState.h"
#include "states/MapHandler.h"
#include "states/PauseState.h"
#include <curses.h>
#include <ncurses.h>
#include <iostream>

int main(){

    // Create gameManager istance, which is a Singleton.
    // GetIstance() either returns the existing istance or creates a new one.
    GameManager* gameManager = GameManager::GetInstance();

    // Set window settings to play the game
    gameManager->setSetting("W_HEIGHT", 10);
    gameManager->setSetting("W_WIDTH", 20);

    // Run initialization for various game components, like renderers
    gameManager->initialize();

    // Run the game loop of the context field
    gameManager->runGameLoop();

    // Run finalization for various game Components
    gameManager->finalize();


    // gameManager istance will be automatically deleted 
    // since it's a singleton
    return 0;
}

