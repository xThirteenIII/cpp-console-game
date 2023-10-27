#include <map>
#include <mutex>
#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

// GameManager class will manage global game settings and keep track of the game's current state.
// It is designed like a Singleton to ensure that there's only one instance throughout the game.
// Thread-safe version including mutex.
class GameManager{

private: 

   static GameManager* instance_;
   static std::mutex mutex_;

   // Constructor
   GameManager();

   // Destructor
   ~GameManager();

   // Use a map to store game setting as key-value pairs
   std::map<std::string, std::string> gameSettings;




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

    // Initialize game settings and other necessary components
    void initilize();

    // Implement game loop, where you switch between game states.
    void runGameLoop();

    // Set a game setting
    void setSetting(const std::string& key, const std::string& value);

    // Get a game setting
    std::string getSetting(const std::string& key);
}; 

#endif

