#ifndef _MAPHANDLER_H_
#define _MAPHANDLER_H_
#include "Context.h"
#include "GameState.h"
#include "../globals.h"
#include "../renderer/RendererAdapter.h"
#include "ncurses.h"
#include <vector>



class MapHandler{
private:
    int rows;
    int columns;

    RendererAdapter* renderer_;

    // Default map, useful for when the game resets
    std::vector< std::vector<char> > initialMap;

    // Current state map, stores the currently displayed state
    std::vector< std::vector<char> > currentMap;

    // Previous state map, it will be swapped with current in the update() method
    std::vector< std::vector<char> > previousMap;



public:

    // Default constructor
    MapHandler();

    // Constructor with custom parameters
    MapHandler(int rows, int columns, RendererAdapter* renderer);

    void initializeMap();
    void update(GameState* currentState);
    void renderMap();
    void finalize();
};
#endif
