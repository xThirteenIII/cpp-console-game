#include "Context.h"
#include "GameState.h"
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
    while (/*game is running*/){
        // enter() is how the GameState handles the request
        this->currentState_->enter();
        this->currentState_->update();
        this->currentState_->exit();
    }
}

