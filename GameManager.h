#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_
#include "characters/AbstractEntity.h"
#include "states/MapHandler.h"
#include <map>
#include <mutex>
#include <string>

// GameManager class will manage global game settings and keep track of the game's current state.
// It is designed like a Singleton to ensure that there's only one instance throughout the game.
// Thread-safe version including mutex.
class GameManager{

private: 

   static GameManager* instance_;
   static std::mutex mutex_;

   int inputKey;

   // Constructor
   GameManager();

   // Destructor
   ~GameManager();

   // Use a map to store game setting as key-value pairs
   std::map<std::string, int> gameSettings;

   MapHandler mapHandler;

   AbstractEntity* player_;
   AbstractEntity* npc_;

public:
/** This means that
 *  Singleton original("Original");
 *  Singleton copy(original); // Attempt to copy using the copy constructor will generate a compile error. 
 *  Same as 
 *  Singleton original("Original");
 *  Singleton another("Another");
 *  another = original; // Attempt to assign one Singleton to another
 */
    // Avoid copy and assign constructors
    GameManager(GameManager &other) = delete;
    void operator=(const GameManager &) = delete;
/**
 * This is the static method that controls the access to the singleton
 * instance. On the first run, it creates a singleton object and places it
 * into the static field. On subsequent runs, it returns the client existing
 * object stored in the static field.
 */
    static GameManager* GetInstance();

    

    MapHandler &getMapHandler();

    // These allow to set Player and Enemy stats
    void setPlayer(AbstractEntity* player);
    void setNPC(AbstractEntity* npc);

    // These allow to access Player and Enemy stats
    AbstractEntity* getPlayer();
    AbstractEntity* getNPC();

    void readInputKey();
    int getInputKey();

    // Initialize game settings and other necessary components
    void initialize();

    // Implement game loop, where you switch between game states.
    void runGameLoop();

    // Set a game setting
    void setSetting(const std::string& key, const int& value);

    // Get a game setting
    int getSetting(const std::string& key);

    // Clean up settings and libraries
    void finalize();
}; 

#endif

