#ifndef _MAPHANDLER_H_
#define _MAPHANDLER_H_
#include "Context.h"
#include "GameState.h"
#include "../globals.h"
#include "../renderer/RendererAdapter.h"
#include "ncurses.h"



class MapHandler{
private:
    int rows;
    int columns;

    RendererAdapter* renderer_;

public:
    // Constructor
    MapHandler(int rows, int columns, RendererAdapter* renderer);

    void initializeMap();
    void update(GameState* currentState);

};
#endif
