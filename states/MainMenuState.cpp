#include "MainMenuState.h"
#include "../ui/Menu.h"
#include "Context.h"
#include <iostream>
#include <string>
#include <vector>

MainMenuState::MainMenuState():mainMenu(nullptr){

    // If it gives an error is due to using an old c++ std version
    std::vector<std::string> menuItems{"Start Game", "Quit Game"};

    // Need to do this because it gives errors if i try to initialize
    // after declaration!
    //menuItems.push_back("Start Game");
    //menuItems.push_back("Quit Game");

    mainMenu = new Menu(menuItems);
}

void MainMenuState::enter(){
    mainMenu->display();
}

void MainMenuState::update(){
    // Handle main menu logic
    mainMenu->getSelection();
    
}

void MainMenuState::exit(){
}
