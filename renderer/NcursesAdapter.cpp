#include "NcursesAdapter.h"
#include <ncurses.h>

void NcursesRenderer::initialize(){

    // Init ncurses library
    initscr();
}

void NcursesRenderer::finalize(){

    // Cleanup and close ncurses library
    endwin();
}

void NcursesRenderer::handleInput(){
}

void NcursesRenderer::render(){
}
