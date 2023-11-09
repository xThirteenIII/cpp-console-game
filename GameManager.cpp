#include "GameManager.h"
#include "characters/AbstractEntity.h"
#include "states/Context.h"
#include "states/MainMenuState.h"
#include "states/MapHandler.h"
#include <iostream>
#include <mutex>
#ifndef _WIN32
#include "renderer/NcursesAdapter.h"
#include <ncurses.h>
#else
#include <conio.h>
#endif

GameManager* GameManager::instance_=nullptr;
std::mutex GameManager::mutex_;

// Constructor
GameManager::GameManager(){};

// No args deconstructor
GameManager::~GameManager(){};


void GameManager::initialize(){
    // Initialize Map
    mapHandler = new MapHandler(GameManager::GetInstance()->getSetting("W_HEIGHT"), GameManager::GetInstance()->getSetting("W_WIDTH"), nullptr);
    //mapHandler->initialize() is run by the SelectClassState::update() method
}

void GameManager::runGameLoop(){

    // implement game loop
    // Init MainMenu as the first state we enter
    Context* context = new Context(new MainMenuState);

    // Run render specific initialization
    // E.g. for the ncurses library, it is needed to initscr()
    this->mapHandler->getRenderer()->initialize();

    context->runGameLoop();

    // Run render specific finalization
    // E.g. endwin() for ncurses
    this->mapHandler->getRenderer()->finalize();

    delete context;
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
        instance_ = new GameManager();
    }
    return instance_;
}

void GameManager::setSetting(const std::string &key, const int &value){
    std::lock_guard<std::mutex> lock(mutex_);
    gameSettings[key] = value;
}

int GameManager::getSetting(const std::string &key){
    std::lock_guard<std::mutex> lock(mutex_);
    // this returns an iterator to the element if the key is found, or it returns an iterator equal to gameSettings.end() if the key is not found.
    auto iterator = gameSettings.find(key);
    if (iterator != gameSettings.end()){

        //In a std::map, the first part of the pair is the key, and the second part is the value.
        //So, this line returns the value corresponding to the found key.
        return iterator->second;
    }
    // Handle the case where the setting doesn't exist
    return -1; // You can choose a default value or handle it differently
}

MapHandler* GameManager::getMapHandler(){
    return this->mapHandler;
}

void GameManager::finalize(){
    this->mapHandler->finalize();
}

void GameManager::readInputKey(){
    timeout(3);
    this->inputKey = getch();
}

int GameManager::getInputKey(){
    return this->inputKey;
}

AbstractEntity* GameManager::getPlayer(){
    return this->player_;
}

AbstractEntity* GameManager::getNPC(){
    return this->npc_;
}

void GameManager::setPlayer(AbstractEntity* player){
    
    // Is this assignment correct?
    this->player_ = player;    
}

void GameManager::setNPC(AbstractEntity* npc){

    // Is this assignment correct?
    this->npc_ = npc;    
}

void GameManager::resetGame(){
    this->mapHandler->initializeMap();
    delete this->player_;
    delete this->npc_;
}

