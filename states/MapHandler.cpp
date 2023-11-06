#include "MapHandler.h"
#include "GameOverState.h"
#include "GameRunningState.h"
#include "GameState.h"
#include "MainMenuState.h"
#include "PauseState.h"
#include "../globals.h"
#include <cstddef>
#include <ncurses.h>
#include <iostream>

MapHandler::MapHandler(Context* context) : context_(context){}

void MapHandler::update(GameState* currentState){
    // Check the current game state and render accordingly
    if (dynamic_cast<GameRunningState*>(currentState) != nullptr){
       printGameMap(); 
    }else if (dynamic_cast<PauseState*>(currentState) != nullptr){
        std::cout << "PAUSE MENU" << std::endl;
    }else if (dynamic_cast<MainMenuState*>(currentState) != nullptr){
        std::cout << "MAIN MENU" << std::endl;
    }else if (dynamic_cast<GameOverState*>(currentState) != nullptr){
        std::cout << "YOU DIED" << std::endl;
    }
}

void MapHandler::printGameMap(){
       // Clear and print the map
    //std::cout << "\033[2J"; // ANSI escape code to clear the screen
    //std::cout << "\033[H";  // ANSI escape code to move the cursor to the top
    /*
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << currentMap[i][j];
        }
        std::cout << std::endl;
    }*/
    // Draw the top row of X's
    mvprintw(0, 0, "###########");

    // Draw the left and right vertical edges
    for (int i = 1; i < 5; i++) {
        mvprintw(i, 0, "#");
        mvprintw(i, 10, "#");
    }

    // Draw the bottom row of X's
    mvprintw(5, 0, "###########");}

/* Function to initialize the map with X's
void MapHandler::initializeMap() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            currentMap[i][j] = '█';
        }
    }
}*/
