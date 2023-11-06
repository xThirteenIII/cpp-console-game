#include "Context.h"
#include "GameState.h"
#include "GameOverState.h"
#include "GameRunningState.h"
#include "MainMenuState.h"
#include "PauseState.h"
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
    std::cout << "Context transition to " << typeid(*state).name() << std::endl;

    // Free current state if it's not null
    if (this->currentState_ != nullptr){
        delete this->currentState_;
    }
    this->currentState_ = state;
    this->currentState_->set_context(this);
}

// run is a request from context
void Context::run(){
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
                case 'q':
                    setState(new GameOverState());
                    break;
                default:
                    break;
            }
        }
         
       
        
        // Check for conditions to transition to other states or exit the game
        if (dynamic_cast<GameRunningState*>(this->currentState_) != nullptr) {
            std::cout << "Game running" << std::endl;
            // Handle actions for gameRunningState
        }else if (dynamic_cast<GameOverState*>(this->currentState_) != nullptr) {
            std::cout << "YOU DIED" << std::endl;
            break; // Exit the loop when in the GameOverState
        }else if (dynamic_cast<MainMenuState*>(this->currentState_) != nullptr) {
            std::cout << "In main menu" << std::endl;
            // Handle main menu stuff
        }else if (dynamic_cast<PauseState*>(this->currentState_) != nullptr) {
            std::cout << "In pause menu" << std::endl;
            // Handle pause menu stuff
        }

        this->currentState_->exit();
    }
}



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
