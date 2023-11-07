#include "NcursesAdapter.h"
#include <ncurses.h>

void NcursesAdapter::initialize(){
    // Init ncurses library
    initscr();
    noecho(); // Disable echoing for user input
    curs_set(FALSE); // Hide cursor
}

void NcursesAdapter::finalize(){

    // Cleanup and close ncurses library
    endwin();
}

void NcursesAdapter::handleInput(){
}

void NcursesAdapter::render(){
}
