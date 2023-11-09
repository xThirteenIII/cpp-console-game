#include "WizardFactory.h"
#include "AbstractEntity.h"
#include "PlayerStats.h"
#include "../GameManager.h"
#include <random>

AbstractEntity* WizardFactory::createCharacter() const{
    // Health, Armor, Attack, Precision, x, y
    return new PlayerStats(15, 8, 8, 90, 1, 1);
}

AbstractEntity* WizardFactory::createEnemy() const{
    // Health, Armor, Attack, Precision, x, y
    //
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Define the range for random positions (adjust as needed)
    // Enemy can be positioned anywhere in the map but on the same player position
    std::uniform_int_distribution<int> distributionX(2, GameManager::GetInstance()->getSetting("W_HEIGHT"));
    std::uniform_int_distribution<int> distributionY(2, GameManager::GetInstance()->getSetting("W_WIDTH"));

    // Health, Armor, Attack, Precision, x, y
    return new PlayerStats(8, 3, 5, 90, distributionX(gen), distributionY(gen));
}
