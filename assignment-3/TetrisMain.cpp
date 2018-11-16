// Copyright 2018
// Computer Science
// Author: Christian Leininger

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#include "./Tetris.h"

// Main function.
int main(int argc, char** argv) {
  int key;
  int Timer = 0;
  initializeScreen();
  showTetromino(true);
  while (true) {
    key = getch();
    if (++Timer % 100 == 0) key = KEY_DOWN;
    showTetromino(false);
    moveTetromino(key);
    showTetromino(true);
    fflush(stdout);
    usleep(10 * 1000);
    if (ty == 19) ty = 1;
  }
  endwin();
}
