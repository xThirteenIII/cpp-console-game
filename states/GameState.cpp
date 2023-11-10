#include "GameState.h"

void GameState::set_context(Context* context){
    this->context_ = context;
}

Context* GameState::get_context(){
    return this->context_;
}
