#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

// Forward declaration
//
// The Context class maintains the current game state and runs the game loop
class Context;

// GameState is the abstract base class for different game states
class GameState{
    protected:
        Context* context_;

    public:
        virtual ~GameState(){};
        void set_context(Context* context);


        // These are operations handled by the GameState
        // Context can delegate to the State some ops
        //
        // The enter function sets up the state, update is called on every frame, and exit is used for cleanup.
        virtual void enter() = 0;
        virtual void update() = 0;
        virtual void exit() = 0;
};
#endif
