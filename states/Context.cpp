#include "Context.h"
#include "GameState.h"
#include "GameOverState.h"
#include "GameRunningState.h"
#include "QuitGameState.h"
#include "MainMenuState.h"
#include "MapHandler.h"
#include "PauseState.h"
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

    MapHandler& mapHandler = gameManager->getMapHandler();

    while (true){

        int pressedKey = processUserInput();

        // enter() is how the GameState handles the request
        this->currentState_->enter();
        this->currentState_->update();
    
        if (pressedKey != ERR){

            switch (pressedKey) {
                case 'm':
                    setState(new MainMenuState());
                    break;
                case 'w':
                    setState(new GameRunningState());
                    break;
                case 'p':
                    setState(new PauseState());
                    break;
                case 'd':
                    setState(new GameOverState());
                    break;
                case 'q':
                    setState(new QuitGameState());
                    break;

                default:
                    break;
            }
        }

        mapHandler.update(this->currentState_);
         
       
        if (dynamic_cast<QuitGameState*>(this->currentState_) != nullptr) {
            // Exit game running loop
            break;
        }
        


        this->currentState_->exit();
    }

    mapHandler.finalize();
}



// Might consider to use the Adapter design pattern if things become more complex.
int Context::processUserInput(){

    int pressedKey;

#ifdef _WIN32
    pressedKey = _getch(); // Read character
#else
    timeout(0); // Set non-blocking input
    pressedKey = getch();
#endif
    
    return pressedKey;
}
