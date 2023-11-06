#include "GameRunningState.h"
#include <iostream>

void GameRunningState::enter(){
    std::cout<< "Entering Game Running State." << std::endl;

}
void GameRunningState::update(){
    std::cout<< "Updating Game Running State." << std::endl;

}
void GameRunningState::exit(){
    std::cout<< "Exiting Game Running State." << std::endl;
}
