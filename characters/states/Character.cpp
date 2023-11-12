#include "Character.h"
#include "CharacterState.h"
#include "IdleState.h"

Character::Character(){

    // Set idleState as initial character state when creating object
    this->currentState_ = new IdleState();
}

Character::~Character() {
    delete currentState_; // Clean up current state
}

void Character::setState(CharacterState* newState){
    if (this->currentState_ != nullptr){
        delete this->currentState_;
    }
    this->currentState_ = newState;
}

CharacterState* Character::getCurrentState() const{
    return this->currentState_;
}

CharacterState* Character::getPreviousState() const{
    return this->previousState_;
}
