#include "MainMenuState.h"
#include <iostream>

void MainMenuState::enter(){
    std::cout << "Entering main menu state." << std::endl;
    // Initialize main menu
}

void MainMenuState::update(){
    std::cout << "Updating main menu state." << std::endl;
    // Handle main menu logic
}

void MainMenuState::exit(){
    std::cout << "Exiting main menu state." << std::endl;
    // Cleanup for main menu
}
