#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include "GameState.h"
class Context{
    private:
        GameState* currentState_;
        GameState* previousState_;
    public:
        //Constructor
        Context(GameState* state);
        //Destructor
        ~Context(); 
      /**
       * The Context allows changing the State object at runtime.
       * The Context delegates part of its behavior to the current State object.
       */
        void setState(GameState* state);
        void switchState();

        // The run method enters, updates, and exits the current state in the game loop.
        void runGameLoop();
        void runCombatLoop();
};
#endif
