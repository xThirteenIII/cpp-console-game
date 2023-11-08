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

       this->x += deltaX; 
       this->y += deltaY;
}
