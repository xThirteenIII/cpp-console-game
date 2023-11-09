# cpp-console-game
Text adventure console game to train with OOP

Download game file and run ./game in the terminal to start it.

Works on unix systems only (MacOS and Linux).
Will implement Windows support later in the future.

If you want to compile the game by yourself, in case the 'game' file doesn't work:

1) Install ncurses library first

---MacOS---
Install with brew:

`brew install ncurses`


---Linux---
run this on terminal:


`sudo apt-get install libncurses5-dev libncursesw5-dev`

2) Compile file from the cpp-console-game directory:

`g++ -Wall -std=c++20 -o game -I./states -I./renderer -I./characters -I./ui *.cpp ./states/*.cpp ./renderer/*.cpp ./ui/*.cpp ./characters/*.cpp -lncurses`

3) Run it from terminal:
`./game`

Commands:
- Use <kbd>Arrow Up</kbd>,<kbd>Arrow Down</kbd>,<kbd>Arrow Left</kbd> and <kbd>Arrow Right</kbd> to navigate menus
- Use <kbd>Enter</kbd> to select
- Use <kbd>w</kbd>, <kbd>a</kbd>, <kbd>s</kbd>, and <kbd>d</kbd> to move through the map
- <kbd>Shift</kbd> + <kbd>q</kbd> to close the game or quit from Main Menu
- Use <kbd>p</kbd> to pause game when playing
- <kbd>Ctrl</kbd> + <kbd>+</kbd> to resize terminal window (<kbd>Cmd</kbd> + <kbd>+</kbd> on Mac) if the
  game map is too small
