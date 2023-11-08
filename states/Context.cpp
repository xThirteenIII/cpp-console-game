#include "Context.h"
#include "GameState.h"
#include "GameOverState.h"
#include "GameRunningState.h"
#include "QuitGameState.h"
#include "MainMenuState.h"
#include "MapHandler.h"
#include "PauseState.h"
#include "../ui/Menu.h"
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
                case 'm':
                    setState(new MainMenuState());
                    break;
                case 'w':
                    setState(new GameRunningState());
                    break;
                case 'a':
                    setState(new GameRunningState());
                    break;
                case 's':
                    setState(new GameRunningState());
                    break;
                case 'd':
                    setState(new GameRunningState());
                    break;
                case 'p':
                    setState(new PauseState());
                    break;
                case 'f':
                    setState(new GameOverState());
                    break;
                case 'q':
                    setState(new QuitGameState());
                    break;

                default:
                    break;
            }
        }

}

// run is a request from context
void Context::run(){

    // Get game istance
    GameManager* gameManager = GameManager::GetInstance();

    // Get map istance
    MapHandler& mapHandler = gameManager->getMapHandler();

    // Get Renderer istance
    RendererAdapter* renderer = mapHandler.getRenderer();

    // Run render specific initialization
    // E.g. for the ncurses library, it is needed to initscr()
    renderer->initialize();

    // Game loop, each iteration corresponds to a frame
    // It runs until the player decides to quit either pressing q or 
    // selecting quit game from the main menu
    while (true){

        // This allows to keep a previous frame map and a current frame map, useful
        // for reducing screen flickering and to save states
        mapHandler.swapMaps();
        
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
        this->currentState_->update();

        // As for now update just clears screen and calls refresh() to print the render
        mapHandler.update(this->currentState_, this->previousState_);
         
       
        // Exit the run() loop thus quitting the game if we're in the QuitGameState
        if (dynamic_cast<QuitGameState*>(this->currentState_) != nullptr) {
            break;
        }

        // Run State specific final stuff (empty for now)
        this->currentState_->exit();
    }

    // Run renderer specific functions, like endwin() for ncurses
    renderer->finalize();
}
