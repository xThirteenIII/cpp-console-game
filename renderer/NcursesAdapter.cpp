#include "NcursesAdapter.h"
#include <ncurses.h>

void NcursesAdapter::initialize(){
    // Init ncurses library
    initscr();
    noecho(); // Disable echoing for user input
    curs_set(FALSE); // Hide cursor
    keypad(stdscr, TRUE);  // Enable special keys
}

void NcursesAdapter::finalize(){
    // Cleanup and close ncurses library
    endwin();
}

int NcursesAdapter::handleInput(){
    // Does the timeout go here?
    timeout(0); // Set non-blocking input
    return getch();
}

void NcursesAdapter::render(){
    refresh(); // Updates screen with the changes made by mvprintw
}
