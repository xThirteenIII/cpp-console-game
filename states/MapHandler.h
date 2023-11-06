#ifndef _MAPHANDLER_H_
#define _MAPHANDLER_H_
#include "Context.h"
#include "GameState.h"
#include "../globals.h"



class MapHandler{
private:
    Context* context_;
    char currentMap[5][10];

    void printGameMap();
    void printStateMenus();
public:
    MapHandler(Context* context);

    void initializeMap();
    void update(GameState* currentState);

};
#endif
