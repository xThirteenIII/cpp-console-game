#include "MapHandler.h"
#include "GameOverState.h"
#include "GameRunningState.h"
#include "GameState.h"
#include "MainMenuState.h"
#include "PauseState.h"
#include "../globals.h"
#include "../GameManager.h"
#include "../renderer/NcursesAdapter.h"
#include <cstddef>
#include <ncurses.h>
#include <iostream>
#include <vector>

MapHandler::MapHandler(int rows, int columns, RendererAdapter* renderer): rows(rows), columns(columns), renderer_(renderer){
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

void MapHandler::renderMap(){

    // Do i have to do it every frame? Naaaah i think not
    renderer_->initialize();
    renderer_->finalize();
}

void MapHandler::initializeMap(){
    rows = GameManager::GetInstance()->getSetting("ROWS");
    columns = GameManager::GetInstance()->getSetting("COLS");

    if (renderer_ == nullptr){
    #ifndef _WIN32
        renderer_ = new NcursesAdapter();
    #else
        renderer_ = new ConioAdapter();
    #endif
        renderer_->initialize();
    }

    std::vector<std::vector<char> >initialMap(rows,std::vector<char>(columns, '.')); // Fill map with dots

    // Fill the walls with #
    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++){
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1) {
                initialMap[i][j] = '#';
            }
        }
    }
}
