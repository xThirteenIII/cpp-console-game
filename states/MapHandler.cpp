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

// Ignore error due to older c++ standard
const char* gameBoyArt = R"(
    ______________________________
   | oON                          |
   | .--------------------------. |
   | |  .--------------------.  | |
   | |  |                    |  | |
   | |))|                    |  | |
   | |  |                    |  | |
   | |  |                    |  | |
   | |  |                    |  | |
   | |  |                    |  | |
   | |  |                    |  | |
   | |  |                    |  | |
   | |  |                    |  | |
   | |  |                    |  | |
   | |  '--------------------'  | |
   | |__GAME BOY________________/ |
   |               ________       |
   |    .            (13)         |
   |  _| |_        """"""""  .-.  |
   |-[_   _]-           .-. (   ) |
   |   |_|             (   ) '-'  |
   |    '               '-'   A   |
   |                     B        |
   |              ___   ___       |
   |             (___) (___)  ,., |
   |            select start ;:;: |
   |                        ,;:;' /
   |                       ,:;:'.'
   '---------------------------`
)";

// Default constructor
MapHandler::MapHandler():rows_(20), columns_(10), renderer_(nullptr){

}

MapHandler::MapHandler(int rows, int columns, RendererAdapter* renderer)
    : rows_(rows),
    columns_(columns),
    // Fills default map with dots
    initialMap_(rows, std::vector<char>(columns, '.')),
    currentMap_(rows, std::vector<char>(columns, '.')),
    previousMap_(rows, std::vector<char>(columns, '.')){

    renderer_ = renderer;
    if (renderer_ == nullptr){
        #ifndef _WIN32
            renderer_ = new NcursesAdapter();
        #else
            renderer_ = new ConioAdapter();
        #endif
    }

    // Fill the walls with .
    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++){
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1) {
                initialMap_[i][j] = '.';
            }
        }
    }

}


void MapHandler::initializeMap(){

    // Init currentMap and previousMap as the default one
    // This causes segmentation fault.
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns_; j++) {
            previousMap_[i][j] = initialMap_[i][j];
            currentMap_[i][j]= initialMap_[i][j];
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
    mvprintw(0,0,"%s", gameBoyArt);
    int gameBoyStartX = 5;
    int gameBoyStartY = 9;
    GameManager* gameManager = GameManager::GetInstance();

    // Update player icon
    currentMap_[gameManager->getPlayer()->getPosition().first][gameManager->getPlayer()->getPosition().second]='P';

    // Update enemy icon if enemey is still alive
    if (gameManager->getNPC()->getHealthPoints() > 0){
        currentMap_[gameManager->getNPC()->getPosition().first][gameManager->getNPC()->getPosition().second]='E';
    }

    // Update fighting icon
    if (gameManager->getPlayer()->getPosition() == gameManager->getNPC()->getPosition()){
        currentMap_[gameManager->getPlayer()->getPosition().first][gameManager->getPlayer()->getPosition().second]='X';
    }


    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns_; j++) {
                char mapChar = currentMap_[i][j];
                mvprintw(gameBoyStartX+i, gameBoyStartY+j, "%c", mapChar);
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
    currentMap_[playerX][playerY] = '.';

    // Copy the current map into the previous map
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns_; j++) {
            previousMap_[i][j] = currentMap_[i][j];
        }
    }



}

RendererAdapter* MapHandler::getRenderer(){
    return renderer_;
}
