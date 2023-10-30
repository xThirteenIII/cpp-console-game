#include "GameManager.h"
#include <iostream>
#include <mutex>

GameManager* GameManager::instance_=nullptr;
std::mutex GameManager::mutex_;

// Constructor
GameManager::GameManager(){};

// No args deconstructor
GameManager::~GameManager(){};


void GameManager::initialize(){
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

void GameManager::setSetting(const std::string &key, const std::string &value){
    std::lock_guard<std::mutex> lock(mutex_);
    gameSettings[key] = value;
}

std::string GameManager::getSetting(const std::string &key){
    std::lock_guard<std::mutex> lock(mutex_);
    // this returns an iterator to the element if the key is found, or it returns an iterator equal to gameSettings.end() if the key is not found.
    auto iterator = gameSettings.find(key);
    if (iterator != gameSettings.end()){
        //In a std::map, the first part of the pair is the key, and the second part is the value.
        //So, this line returns the value corresponding to the found key.
        return iterator->second;
    }
    // Handle the case where the setting doesn't exist
    return ""; // You can choose a default value or handle it differently
}
