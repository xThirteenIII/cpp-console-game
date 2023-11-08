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
    initialMap(rows, std::vector<char>(columns, '.')){

    renderer_ = renderer;
    if (renderer_ == nullptr){
        #ifndef _WIN32
            renderer_ = new NcursesAdapter();
        #else
            renderer_ = new ConioAdapter();
        #endif
        renderer_->initialize();
    }
}


void MapHandler::initializeMap(){
    // Fill the walls with #
    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++){
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1) {
                initialMap[i][j] = '#';
            }
        }
    }

    // Init currentMap and previousMap as the default one
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            previousMap[i][j] = initialMap[i][j];
            currentMap[i][j]= initialMap[i][j];
        }
    }
}

void MapHandler::update(GameState* currentState){
    clear();
    // Check the current game state and render accordingly
    if (dynamic_cast<GameRunningState*>(currentState) != nullptr){
        this->renderMap();
    }else if (dynamic_cast<PauseState*>(currentState) != nullptr){
        std::cout << "PAUSE MENU" << std::endl;
    }else if (dynamic_cast<MainMenuState*>(currentState) != nullptr){
        std::cout << "MAIN MENU" << std::endl;
    }else if (dynamic_cast<GameOverState*>(currentState) != nullptr){
        std::cout << "YOU DIED" << std::endl;
    }
}

void MapHandler::renderMap(){
    GameManager* gameManager = GameManager::GetInstance();

    // Update player position
    currentMap[gameManager->getPlayer()->getX()][gameManager->getPlayer()->getY()]='P';

    // Do i have to do it every frame? Naaaah i think not
    //renderer_->initialize();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            char mapChar = currentMap[i][j];
            mvprintw(i, j, "%c", mapChar);
        }
    }
    renderer_->render();
}


void MapHandler::finalize(){

    // Clean up libraries if needed
    renderer_->finalize();
}

// Be sure to call this before upgrading player/character positions
void MapHandler::swapMaps(){

    GameManager* gameManager = GameManager::GetInstance();

    int playerX = gameManager->getPlayer()->getX();
    int playerY = gameManager->getPlayer()->getY();

    // Copy the current map into the previous map
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            previousMap[i][j] = currentMap[i][j];
        }
    }

    // Re-insert a dot in the previous player position
    currentMap[playerX][playerY] = '.';


}
