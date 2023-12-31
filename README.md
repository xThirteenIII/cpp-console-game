# cpp-console-game

# Table of Contents
- [Download and Play](#download-and-run-game-file)
- [Compile and run](#compile-and-run)
  - [Install dependencies](##install-ncurses-library-first)
  - [Compile .cpp files](##compile-file-from-the-cpp-console-game-directory)
  - [Run executable](##run-from-terminal)
- [Commands](#commands)

Text adventure console game to train with OOP

## Download and run game file

Download game file and run `./game` in the terminal to start it.

Works on unix systems only (MacOS and Linux).

Will implement Windows support later in the future.

## Compile and run

If you want to compile the game by yourself, in case the 'game' file doesn't work:

### 1) Install ncurses library first

---MacOS--- 🍎

Install with brew:

`brew install ncurses`


---Linux--- 🐧  (Ubuntu/Debian)

run this on terminal:

`sudo apt-get install libncurses5-dev libncursesw5-dev`

### 2) Install g++ compiler

check if g++ is already installed first with:

`g++ --version`

if it's not installed yet get developer tools:

`sudo apt update`

`sudo apt install build-essential`

the above meta-package installs the number of packages including g++ automatically, gcc, and make.

### 3) Compile file from the cpp-console-game directory

`g++ -Wall -std=c++20 -o game -I./states -I./renderer -I./characters -I./ui -I./combat *.cpp ./states/*.cpp ./renderer/*.cpp ./ui/*.cpp ./characters/*/*.cpp ./combat/*.cpp -lncurses`

### 4) Run from terminal

`./game`

## Commands:
- Use <kbd>Arrow Up</kbd>,<kbd>Arrow Down</kbd>,<kbd>Arrow Left</kbd> and <kbd>Arrow Right</kbd> to navigate menus
- Use <kbd>Enter</kbd> to select
- Use <kbd>w</kbd>, <kbd>a</kbd>, <kbd>s</kbd>, and <kbd>d</kbd> to move through the map
- <kbd>Shift</kbd> + <kbd>q</kbd> to close the game or quit from Main Menu
- Use <kbd>p</kbd> to pause game when playing
- <kbd>Ctrl</kbd> + <kbd>+</kbd> to resize terminal window (<kbd>Cmd</kbd> + <kbd>+</kbd> on Mac) if the
  game map is too small
