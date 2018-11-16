// Copyright 2018
// Computer Science
// Author: Christian Leininger ChristianLeininger@gmx.de

#include <ncurses.h>
#include <unistd.h>
#include "./Tetris.h"

// _____________________________________________________________________________
int sx = 5;  // strech length
int sy = 3;  // strech high

// _____________________________________________________________________________
int tx = 9;   // start point length
int ty = 2;   // start point hight

// _____________________________________________________________________________
// Positions for the J Tetromino
int t1x = 0;
int t2x = 1;
int t3x = -1;
int t4x = -1;
int t1y = 0;
int t2y = 0;
int t3y = 0;
int t4y = -1;

// _____________________________________________________________________________
void initializeScreen() {
  initscr();  // Initialization.
  cbreak();  // Don't wait for RETURN.
  noecho();  // Don't echo key pressed on screen.
  curs_set(false);  // Don't show the cursor.
  nodelay(stdscr, true);  // Don't wait for key pressed.
  keypad(stdscr, true);  // Special codes for KEY_LEFT, KEY_UP, ...
}

// _____________________________________________________________________________
void showTetromino(bool showOrDelete) {
  if (showOrDelete == true) printf("\x1b[7m");
  if (ty == 19)printf("\x1b[31m");  // print red at bottom
  for (int i = 0; i <  sx; i++) {
    for (int j = 0; j <  sy; j++) {
      printf("\x1b[%d;%dH ", (ty + t1y) * sy + j, (tx +t1x) * sx + i);
      printf("\x1b[%d;%dH ", (ty + t2y) * sy + j, (tx +t2x) * sx + i);
      printf("\x1b[%d;%dH ", (ty + t3y) * sy + j, (tx +t3x) * sx + i);
      printf("\x1b[%d;%dH ", (ty + t4y) * sy + j, (tx +t4x) * sx + i);
    }
  }
  printf("\x1b[0m");
}

// _____________________________________________________________________________
void moveTetromino(int key) {
  switch (key) {
    case KEY_UP:
      // Not implented yet
      break;
    case KEY_DOWN:
      if (ty < 22) ty++;  // move down
      break;
    case KEY_LEFT:
      if (tx > 4) tx--;  // move left
      break;
    case KEY_RIGHT:
      if (tx < 14) tx++;  // move right
      break;
  }
}
