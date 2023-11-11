#include "PhilosopherFactory.h"
#include "AbstractEntity.h"
#include "PlayerObject.h"
#include "../../GameManager.h"
#include <random>

AbstractEntity* PhilosopherFactory::createCharacter() const{
    // Health, Armor, Attack, Precision, x, y
    return new PlayerObject(15, 8, 8, 90, 0, 0);
}

AbstractEntity* PhilosopherFactory::createEnemy() const{
    // Health, Armor, Attack, Precision, x, y
    //
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Define the range for random positions (adjust as needed)
    // Enemy can be positioned anywhere in the map but on the same player position
    std::uniform_int_distribution<int> distributionX(1, GameManager::GetInstance()->getSetting("W_HEIGHT") - 1);

    // Spawn enemy in the right half of the map
    std::uniform_int_distribution<int> distributionY(GameManager::GetInstance()->getSetting("W_WIDTH")/2, GameManager::GetInstance()->getSetting("W_WIDTH")-1);


    // Health, Armor, Attack, Precision, x, y
    return new PlayerObject(8, 3, 5, 90, distributionX(gen), distributionY(gen));
}
