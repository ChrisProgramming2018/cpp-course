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
  bool structure[20][10] = {0};
  bool bottomReached = false;
  int key;
  int timer = 0;
  initializeScreen();
  showTetromino(true, false);
  while (true) {
    key = getch();
    // to fall slowly
    if (++timer % 50 == 0) key = KEY_DOWN;
    showTetromino(false, false);
    // moves it one down to check for collison
    moveTetromino(KEY_DOWN, false);
    bottomReached = checkCollision();
    moveTetromino(KEY_DOWN, true);
    if (bottomReached) {
      showTetromino(true, bottomReached);
      bool gameOver = addTetrominoToStructure();
      if (gameOver) {
        printf("\x1b[20;20H");
        printf("\x1b[34m");
        printf("\x1b[7m");
        printf("Game Over");
        usleep(1000 * 1000);
        fflush(stdin);
        getchar();
        break;
      }
      removeFullRowsFromStructure();
      drawStructure();
      ty = 0;
      tx = 4;
      resetTetromino();
      timer = 0;
    }
    showTetromino(false, false);
    // check if it hits the border
    moveTetromino(key, false);
    if (checkCollision()) moveTetromino(key, true);
    showTetromino(true, false);
    fflush(stdout);
    usleep(10 * 1000);   // wait 10 milsec
  }
  endwin();
}
