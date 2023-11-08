#include "MainMenuState.h"
#include "../ui/Menu.h"
#include "Context.h"
#include <iostream>
#include <string>
#include <vector>

MainMenuState::MainMenuState():mainMenu(new Menu(std::vector<std::string>{"Start Game", "Quit Game"})){};

void MainMenuState::enter(){
    mainMenu->display();
}

void MainMenuState::update(){
    // Handle main menu logic
    mainMenu->getSelection();
    
}

void MainMenuState::exit(){
}
