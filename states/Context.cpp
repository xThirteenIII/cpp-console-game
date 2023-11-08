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

void Context::switchState(){

        if (GameManager::GetInstance()->getInputKey() != ERR){

            switch (GameManager::GetInstance()->getInputKey()) {
                case 'm':
                    setState(new MainMenuState());
                    break;
                case 'w':
                    setState(new GameRunningState());
                    break;
                case 'a':
                    setState(new GameRunningState());
                    break;
                case 's':
                    setState(new GameRunningState());
                    break;
                case 'd':
                    setState(new GameRunningState());
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

}

// run is a request from context
void Context::run(){

    GameManager* gameManager = GameManager::GetInstance();

    MapHandler& mapHandler = gameManager->getMapHandler();

    RendererAdapter* renderer = mapHandler.getRenderer();
    renderer->initialize();

    

    while (true){
        mapHandler.swapMaps();
        
        // Store key pressed by the user in private inputKey field in the GameManager single istance
        gameManager->readInputKey();

        // Store previous state
        this->previousState_ = this->currentState_;

        // enter() is how the GameState handles the request
        this->currentState_->enter();

        this->switchState();

        this->currentState_->update();
        mapHandler.update(this->currentState_, this->previousState_);
         
       
        if (dynamic_cast<QuitGameState*>(this->currentState_) != nullptr) {
            // Exit game running loop
            break;
        }

        this->currentState_->exit();
    }

    renderer->finalize();
}
