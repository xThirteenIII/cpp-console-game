#include "MapHandler.h"
#include "GameOverState.h"
#include "GameRunningState.h"
#include "GameState.h"
#include "MainMenuState.h"
#include "PauseState.h"
#include "../globals.h"
#include "../GameManager.h"
#include <cstddef>
#include <ncurses.h>
#include <iostream>

MapHandler::MapHandler(int rows, int columns, RendererAdapter* renderer){
    std::cout << "handling map" << std::endl;
}

void MapHandler::update(GameState* currentState){
    // Check the current game state and render accordingly
    if (dynamic_cast<GameRunningState*>(currentState) != nullptr){
       //printGameMap(); 
        std::cout << "MAP" << std::endl;
    }else if (dynamic_cast<PauseState*>(currentState) != nullptr){
        std::cout << "PAUSE MENU" << std::endl;
    }else if (dynamic_cast<MainMenuState*>(currentState) != nullptr){
        std::cout << "MAIN MENU" << std::endl;
    }else if (dynamic_cast<GameOverState*>(currentState) != nullptr){
        std::cout << "YOU DIED" << std::endl;
    }
}

/*void MapHandler::printGameMap(){
    // Get terminal dimensions
    int rows, columns;
    getmaxyx(stdscr, rows, columns);

    // Create two off-screen buffers (one for the current frame and one for the previous frame)
    WINDOW* currentFrameBuffer = newwin(rows, columns, 0, 0);
    WINDOW* previousFrameBuffer = newwin(rows, columns, 0, 0);

    char currentMap[rows][columns];
    char previousMap[rows][columns];

    // Initialize the game map and current/previous frame buffers

    // Draw the top row of X's
    mvwprintw(offScreenBuffer,0, 0, "###########");

    // Draw the left and right vertical edges
    for (int i = 1; i < 5; i++) {
        mvwprintw(offScreenBuffer,i, 0, "#");
        mvwprintw(offScreenBuffer,i, 10, "#");
    }

    // Draw the bottom row of X's
    mvwprintw(offScreenBuffer,5, 0, "###########");
    copywin(offScreenBuffer, stdscr, 0, 0, 0, 0, rows - 1, columns - 1, 0);

}


void MapHandler::initializeMap() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            currentMap[i][j] = '#';
            previous
        }
    }
}
*/
