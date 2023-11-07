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

#ifndef _WIN32
    initscr();// Init ncurses library on macOS and Linux
    noecho(); // Disable echoing for user input
    curs_set(FALSE); // Hide cursor
#endif

    // Create gameManager istance
    // GetIstance() either returns the existing istance or creates a new one.
    GameManager* gameManager = GameManager::GetInstance();
    gameManager->setSetting("W_WIDTH", 10);
    gameManager->setSetting("W_HEIGHT", 5);
    gameManager->initialize();
    gameManager->runGameLoop();


#ifndef _WIN32
    endwin(); // Clean up ncurses library
#endif

    // gameManager istance will be automatically deleted 
    // since it's a singleton
    return 0;
}

