// Copyright 2018
// Computer Science
// Author: Christian Leininger ChristianLeininger@gmx.de

#include <ncurses.h>
#include <unistd.h>
#include "./Tetris.h"

// _____________________________________________________________________________
int sx = 5;  // stretch length
int sy = 3;  // stretch height

// _____________________________________________________________________________
int tx = 4;   // start point length
int ty = 0;   // start point height

// _____________________________________________________________________________
int txr[4]= {0, 0, 0, 0};  // for the straight Tetromino
int tyr[4]= {0, 1, 2, 3};

// _____________________________________________________________________________
bool structure[20][10];  // for the Field

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
void showTetromino(bool showOrDelete, bool bottomReached) {
  if (showOrDelete == true) printf("\x1b[7m");
  if (bottomReached)printf ("\x1b[31m");  // print red at bottom
  for (int i = 0; i < sx; i++) {
    for (int j = 0; j < sy; j++) {
      for (int k = 0; k < 4 ; k++) {
        printf("\x1b[%d;%dH ", (ty + tyr[k]) * sy + j, (tx +txr[k]) * sx + i);
      }
    }
  }
  printf("\x1b[0m");
}

// _____________________________________________________________________________
void moveTetromino(int key, bool reverse) {
  switch (key) {
    case KEY_UP:
      if (reverse == true) rotateTetromino(1);
      if (reverse == false) rotateTetromino(3);
      break;
    case KEY_DOWN:
      if (reverse == true) ty--;
      if (reverse == false) ty++;
      break;
    case KEY_LEFT:
        if (reverse == true) tx++;
        if (reverse == false) tx--;
        break;
    case KEY_RIGHT:
        if (reverse == true) tx--;
        if (reverse == false) tx++;
        break;
  }
}

// _____________________________________________________________________________
void rotateTetromino(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      int xx = txr[j];
      int yy = tyr[j];
      txr[j] = -yy;
      tyr[j] = xx;
    }
  }
}

// _____________________________________________________________________________
bool checkCollision() {
  for (int i = 0; i < 4; i++) {
    int x = tx + txr[i];
    int y = ty + tyr[i];
    if (x < 0 || x > 9) return true;  // left and right limit
    if (y < 0 || y > 19) return true;
    if (structure[y][x] != 0) return true;  // if it hits another Tetromino
  }
  return false;
}

// _____________________________________________________________________________
bool addTetrominoToStructure() {
  for (int i = 0; i < 4; i++) {
    int x = tx + txr[i];
    int y = ty + tyr[i];
    structure[y][x] = true;
  }
  for (int j = 0; j < 10; j++) {
      if (structure[0][j] == true) {
        return true;
      }
  }
  return false;
}

// _____________________________________________________________________________
void removeFullRowsFromStructure() {
  for (int row  = 0; row < 20; row++) {
    bool fullRow = true;
    for (int j = 0; j < 10; j++) {
      if (structure[row][j] == false) fullRow = false;  // gap in row
    }
    if (fullRow) {
      for (int k = row; k > 0; k--) {
        for (int j = 0; j < 10; j++) {
          structure[k][j] = structure[k - 1][j];
        }
      }
    }
  }
}
// _____________________________________________________________________________
void drawStructure() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      if (structure[i][j] == true) {
        printf("\x1b[7m");   // print inverese
        printf("\x1b[31m");  // print red
      } else {
          printf("\x1b[0m");
        }
      for (int m = 0; m < sx; m++) {
        for (int k = 0; k < sy; k++) {
          printf("\x1b[%d;%dH ", i * sy + k, j * sx + m);
        }
      }
    }
  }
}

// _____________________________________________________________________________
void resetTetromino() {
  for (int i = 0; i < 4; i++) {
    txr[i] = 0;  // for the straight Tetromino
  }
  for (int i = 0; i < 4; i++) {
    tyr[i] = i;  // for the straight Tetromino
  }
}
