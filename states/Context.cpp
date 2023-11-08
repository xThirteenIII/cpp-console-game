#include "Context.h"
#include "GameState.h"
#include "GameOverState.h"
#include "GameRunningState.h"
#include "QuitGameState.h"
#include "MainMenuState.h"
#include "MapHandler.h"
#include "PauseState.h"
#include "../ui/Menu.h"
#include "../GameManager.h"
#include "../renderer/NcursesAdapter.h"
#include <iostream>

#ifdef _WIN32
#include <conio.h> // Windows specific input library
#else
#include <ncurses.h> // macOS and Linux
#endif


// Constructor
Context::Context(GameState* state): currentState_(nullptr){
    this->setState(state);
}

// Deconstructor
Context::~Context(){
    delete currentState_;
}

void Context::setState(GameState* state){

    // Free current state if it's not null
    if (this->currentState_ != nullptr){
        delete this->currentState_;
    }
    this->currentState_ = state;
    this->currentState_->set_context(this);
}

// run is a request from context
void Context::run(){

    GameManager* gameManager = GameManager::GetInstance();

    Player* player = gameManager->getPlayer();
    MapHandler& mapHandler = gameManager->getMapHandler();

    RendererAdapter* renderer = mapHandler.getRenderer();
    renderer->initialize();

    

    while (true){
        mapHandler.swapMaps();
        gameManager->readInputKey();

        // Store previous state
        this->previousState_ = this->currentState_;

        // enter() is how the GameState handles the request
        this->currentState_->enter();
        this->currentState_->update();
    
        if (gameManager->getInputKey() != ERR){

            switch (gameManager->getInputKey()) {
                case 'm':
                    setState(new MainMenuState());
                    break;
                case 'w':
                    setState(new GameRunningState());
                    // Move one row up
                    // -1 because you want to go one position less: e.g. from [2][1] to [1][1] to go up
                    player->move(-1,0);
                    break;
                case 'a':
                    setState(new GameRunningState());
                    // Move one column left 
                    // [3][4] to [3][3]
                    player->move(0,-1);
                    break;
                case 's':
                    // Move one row down 
                    // [3][4] to [4][4]
                    player->move(1,0);
                    setState(new GameRunningState());
                    break;
                case 'd':
                    setState(new GameRunningState());
                    // Move one column right 
                    // [3][4] to [3][5]
                    player->move(0,1);
                    break;
                case 'p':
                    setState(new PauseState());
                    break;
                case 'f':
                    setState(new GameOverState());
                    break;
                case 'q':
                    setState(new QuitGameState());
                    break;

                default:
                    break;
            }
        }

        mapHandler.update(this->currentState_, this->previousState_);
         
       
        if (dynamic_cast<QuitGameState*>(this->currentState_) != nullptr) {
            // Exit game running loop
            break;
        }
        


        this->currentState_->exit();
    }

    renderer->finalize();
}
