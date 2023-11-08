#include "NcursesAdapter.h"
#include <ncurses.h>

void NcursesAdapter::initialize(){
    // Init ncurses library
    initscr();
    noecho(); // Disable echoing for user input
    curs_set(FALSE); // Hide cursor
    keypad(stdscr, TRUE);  // Enable special keys
                           //
    // Resize the terminal window to your desired dimensions (e.g., 25 rows and 80 columns)
    //int rows = 25; // Set the number of rows
    //int cols = 80; // Set the number of columns
    //resize_term(rows, cols); // Resize the terminal
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
