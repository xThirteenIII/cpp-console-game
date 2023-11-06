#include "PauseState.h"
#include <iostream>

void PauseState::enter() {
    std::cout << "Entering pause state" << std::endl;
}
void PauseState::update() {
    std::cout << "Updating pause state" << std::endl;
}
void PauseState::exit() {
    std::cout << "Exit pause state" << std::endl;
}
