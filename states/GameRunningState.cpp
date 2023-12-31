#include "GameRunningState.h"
#include "PauseState.h"
#include "CombatState.h"
#include "../GameManager.h"
#include "Context.h"
#include "MapHandler.h"
#include <iostream>

void GameRunningState::enter(){
}
void GameRunningState::update(Context* context){
    // Handle movement logic
    //
    // Move one row up
    // -1 because you want to go one position less: e.g. from [2][1] to [1][1] to go up
    AbstractEntity* player = GameManager::GetInstance()->getPlayer();


    MapHandler* mapHandler = GameManager::GetInstance()->getMapHandler();

    // This allows to keep a previous frame map and a current frame map, useful
    // for reducing screen flickering and to save states
    mapHandler->swapMaps();
    mapHandler->update(this, this);

        
    if (GameManager::GetInstance()->getInputKey() != ERR){
        switch (GameManager::GetInstance()->getInputKey()){
            case 'w':
                player->move(-1,0);
                break;
            case 's':
                // Move one row down 
                // [3][4] to [4][4]
                player->move(1,0);
                break;
            case 'a':
                // Move one column left 
                // [3][4] to [3][3]
                player->move(0,-1);
                break;
            case 'd':
                // Move one column right 
                // [3][4] to [3][5]
                player->move(0,1);
                break;
            case 'p':
                context->setState(new PauseState());
            default:
                break;
        }
    }

    mapHandler->renderMap();

    // If player reaches enemy, start combat state.
    if (GameManager::GetInstance()->getPlayer()->getPosition() == GameManager::GetInstance()->getNPC()->getPosition()){
        context->setState(new CombatState());
    }
}

void GameRunningState::exit(){
}
