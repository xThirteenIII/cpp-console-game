#include "IdleState.h"
#include "AttackState.h"
#include "../../GameManager.h"
#include "CharacterState.h"

void IdleState::enter(){

}

// If player and enemy position overlap, initiate combat:
// player starts first attacking.
void IdleState::update(){
    
    GameManager* gameManager = GameManager::GetInstance();    
    if (gameManager->getPlayer()->getPosition() == gameManager->getNPC()->getPosition()){
        gameManager->getPlayer()->setState(new AttackState());
    }
}

void IdleState::exit(){

}
