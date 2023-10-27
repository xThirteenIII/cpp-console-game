#include "gameManager.h"
#include <iostream>

GameManager* GameManager::instance_=nullptr;
std::mutex GameManager::mutex_;

// Constructor
GameManager::GameManager(){};

// No args deconstructor
GameManager::~GameManager(){};


void GameManager::initilize(){
    // implement settings
}

void GameManager::runGameLoop(){
    // implement game loop
}

// Get the singleton instance
GameManager* GameManager::GetInstance(){

    /**
     * The first time we call GetInstance we will lock the storage location
     *      and then we make sure again that the variable is null and then we
     *      set the value.
     */    

    // Basically whoever comes here first locks the mutex,
    // the other thread has to wait until it is unlocked (which is when the first one
    // ends the job). At that point the pinstance_ is already set and thus the 
    // same istance is reused.
    std::lock_guard<std::mutex> lock(mutex_);

    if (instance_ == nullptr){
        std::cout << "first run" << std::endl;
        instance_ = new GameManager();
    }
    return instance_;
}

