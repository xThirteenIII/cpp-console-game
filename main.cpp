#include "GameManager.h"
#include "states/Context.h"
#include "states/GameOverState.h"
#include "states/GameRunningState.h"
#include "globals.h"
#include "states/GameState.h"
#include "states/MainMenuState.h"
#include "states/PauseState.h"
#include <curses.h>
#include <ncurses.h>
#include <iostream>

void StartGame(Context* context);
void GoToMainMenu(Context* context);
void PauseGame(Context* context);
void Die(Context* context);



int main(){

    // Init ncurses library
    initscr();

    Context* context = new Context(new MainMenuState);
    context->run();

    StartGame(context);
    GoToMainMenu(context);
    PauseGame(context);
    StartGame(context);
    PauseGame(context);
    GoToMainMenu(context);
    Die(context);

    delete context;

    endwin();
    return 0;
}

void StartGame(Context* context){
    context->setState(new GameRunningState);
}
void GoToMainMenu(Context* context){
    context->setState(new MainMenuState);

}
void PauseGame(Context* context){
    context->setState(new PauseState);
}
void Die(Context* context){
    context->setState(new GameOverState);
}
