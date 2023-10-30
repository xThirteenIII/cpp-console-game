#include "GameManager.h"
#include "states/Context.h"
#include "states/GameRunningState.h"

void StartGame();

int main(){
    return 0;
}

void StartGame(){
    Context* context = new Context(new GameRunningState);
    context->run();
}
