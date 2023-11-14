#include "../factory/AbstractEntity.h"
#include "../../GameManager.h"
#include "AttackState.h"
#include "CharacterState.h"

void AttackState::enter(){
    GameManager* gameManager = GameManager::GetInstance();
    AbstractEntity* player = gameManager->getPlayer();
    AbstractEntity* enemyNPC = gameManager->getNPC();
    
}

void AttackState::update(){

}

void AttackState::exit(){

}


