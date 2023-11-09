#include "MapHandler.h"
#include "GameOverState.h"
#include "GameRunningState.h"
#include "GameState.h"
#include "MainMenuState.h"
#include "PauseState.h"
#include "../globals.h"
#include "../ui/Menu.h"
#include "../GameManager.h"
#include "../renderer/NcursesAdapter.h"
#include <cstddef>
#include <iostream>
#include <vector>

#ifndef _WIN32
#include <ncurses.h>
#else
#include <conio.h>
#endif

// Default constructor
MapHandler::MapHandler():rows(20), columns(10), renderer_(nullptr){

}

MapHandler::MapHandler(int rows, int columns, RendererAdapter* renderer)
    : rows(rows),
    columns(columns),
    // Fills default map with dots
    initialMap(rows, std::vector<char>(columns, '.')),
    currentMap(rows, std::vector<char>(columns, '.')),
    previousMap(rows, std::vector<char>(columns, '.')){

    renderer_ = renderer;
    if (renderer_ == nullptr){
        #ifndef _WIN32
            renderer_ = new NcursesAdapter();
        #else
            renderer_ = new ConioAdapter();
        #endif
    }

    // Fill the walls with #
    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++){
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1) {
                initialMap[i][j] = '#';
            }
        }
    }

}


void MapHandler::initializeMap(){

    // Init currentMap and previousMap as the default one
    // This causes segmentation fault.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            previousMap[i][j] = initialMap[i][j];
            currentMap[i][j]= initialMap[i][j];
        }
    }
}

void MapHandler::update(GameState* currentState, GameState* previousState){

    // Clear screen if the state changes
    if (currentState != previousState){
        clear();
    }


    renderer_->render();
}

void MapHandler::renderMap(){
    GameManager* gameManager = GameManager::GetInstance();

    // Update player position
    currentMap[gameManager->getPlayer()->getPosition().first][gameManager->getPlayer()->getPosition().second]='P';

    // Do i have to do it every frame? Naaaah don't think so
    //renderer_->initialize();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
                char mapChar = currentMap[i][j];
                mvprintw(i, j, "%c", mapChar);
        }
    }
}


void MapHandler::finalize(){

    // Clean up libraries if needed
    renderer_->finalize();
}

// Be sure to call this before upgrading player/character positions
void MapHandler::swapMaps(){

    GameManager* gameManager = GameManager::GetInstance();

    int playerX = gameManager->getPlayer()->getPosition().first;
    int playerY = gameManager->getPlayer()->getPosition().second;

    // Re-insert a dot in the previous player position
    currentMap[playerX][playerY] = '.';

    // Copy the current map into the previous map
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            previousMap[i][j] = currentMap[i][j];
        }
    }



}

RendererAdapter* MapHandler::getRenderer(){
    return renderer_;
}
