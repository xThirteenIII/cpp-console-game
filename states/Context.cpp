#include "Context.h"
#include "GameState.h"
#include "GameOverState.h"
#include <iostream>

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
        // enter() is how the GameState handles the request
        this->currentState_->enter();
        this->currentState_->update();
    
        // Check for conditions to transition to other states or exit the game
        if (/* some condition to quit the game */) {
            setState(new GameOverState());
        }
        if (this->currentState_ == ) {
            break; // Exit the loop when in the GameOverState
        }

        this->currentState_->exit();}
}

