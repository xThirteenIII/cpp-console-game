#include "Character.h"
#include "Player.h"
#include "../GameManager.h"

Player::Player(){
    this->x = 1;
    this->y = 1;
}

Player::Player(int x, int y){
    this->x = x;
    this->y = y;
}

void Player::move(int deltaX, int deltaY){

    int boundX = GameManager::GetInstance()->getSetting("W_HEIGHT") - 1;
    int boundY = GameManager::GetInstance()->getSetting("W_WIDTH") - 1;
    

   // Check map boundaries
   if (((this->x + deltaX) < boundX && (this->x + deltaX) > 0) && ((this->y + deltaY) < boundY && (this->y + deltaY) > 0)){
       this->x += deltaX; 
       this->y += deltaY;
   }
}
