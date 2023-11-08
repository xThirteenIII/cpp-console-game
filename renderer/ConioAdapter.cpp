#include "ConioAdapter.h"

#ifdef _WIN32
#include <conio.h>

void ConioAdapter::initialize(){
}

void ConioAdapter::finalize(){
}

int ConioAdapter::handleInput(){
    return _getch();
}

void ConioAdapter::render(){
}
#endif
