#include "EngineerFactory.h"
#include "AbstractEntity.h"
#include "PlayerStats.h"
#include "../GameManager.h"
#include <random>

AbstractEntity* EngineerFactory::createCharacter() const{
    // Health, Armor, Attack, Precision, x, y
    return new PlayerStats(25, 15, 5, 90, 1, 1);
}

AbstractEntity* EngineerFactory::createEnemy() const{
    // Health, Armor, Attack, Precision, x, y
    //
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Define the range for random positions (adjust as needed)
    // Enemy can be positioned anywhere in the map but on the same player position
    std::uniform_int_distribution<int> distributionX(2, GameManager::GetInstance()->getSetting("W_HEIGHT")-1);

    // Spawn enemy in the right half of the map
    std::uniform_int_distribution<int> distributionY(GameManager::GetInstance()->getSetting("W_WIDTH")/2, GameManager::GetInstance()->getSetting("W_WIDTH")-2);

    return new PlayerStats(15, 5, 3, 90, distributionX(gen), distributionY(gen));
}