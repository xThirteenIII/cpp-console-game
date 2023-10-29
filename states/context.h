#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include "gameState.h"
class Context{
    private:
        GameState* currentState;
    public:
        //Constructor
        Context(GameState* state);
        //Destructor
        ~Context(); 
};
#endif
