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

// Libraries for input handling and screen printing
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

// Switch from one State to another based on user input, stored
// in the inputKey private field in the GameManager istance
void Context::switchState(){

        if (GameManager::GetInstance()->getInputKey() != ERR){

            switch (GameManager::GetInstance()->getInputKey()) {
                case 'p':
                    // Go into pause menu only if in GameRunningState
                    if (dynamic_cast<GameRunningState*>(this->currentState_) != nullptr){
                        setState(new PauseState());
                    }
                    break;

                    // Use capital Q to quit to avoid accidental key press
                case 'Q':
                    setState(new QuitGameState());
                    break;
                default:
                    break;
            }
        }

}

// run is a request from context
void Context::runGameLoop(){

    // Get game istance
    GameManager* gameManager = GameManager::GetInstance();

    // Set default attacks for both player and enemy
    // Is it ok to do it here or is there a better place?



    // Get map istance
    MapHandler* mapHandler = gameManager->getMapHandler();

    // Game loop, each iteration corresponds to a frame
    // It runs until the player decides to quit either pressing q or 
    // selecting quit game from the main menu
    while (true){

        // Store key pressed by the user in private inputKey field in the GameManager single istance
        //
        // This must be the only place where to read the input, otherwise it gets latency when pressing 
        // keys 
        gameManager->readInputKey();
        
        // This is needed to clear the screen only if we switch to a different state
        this->previousState_ = this->currentState_;

        // enter() is how the GameState handles the request
        this->currentState_->enter();

        // Switch the state based on the input pressed
        this->switchState();

        // Update the current state, handling screen update and State specific logic
        this->currentState_->update(this);

        // As for now update just clears screen and calls refresh() to print the render
        mapHandler->update(this->currentState_, this->previousState_);

        // Run State specific final stuff (empty for now)
        this->currentState_->exit();

        // Exit the run() loop thus quitting the game if we're in the QuitGameState
        if (dynamic_cast<QuitGameState*>(this->currentState_) != nullptr) {
            break;
        }
    }
}
