// Copyright 2018
// Computer Science
// Author: Christian Leininger ChristianLeininger@gmx.de

#include "./Structure.h"
#include <stdio.h>

// __________________________________________________________________
Structure::Structure() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      _cells[i][j]= 0;
    }
  }
}

// __________________________________________________________________
void Structure::addTetromino(Tetromino tetromino) {
  for (int i = 0; i < 4; i++) {
    int x = tetromino._tx + tetromino._txr[i];
    int y = tetromino._ty + tetromino._tyr[i];
    _cells[x][y] = 1;
  }
}

// __________________________________________________________________
bool Structure::checkCollision(Tetromino tetromino) {
  for (int i = 0; i < 4 ; i++) {
    int x = tetromino._tx + tetromino._txr[i];
    int y = tetromino._ty + tetromino._tyr[i];
    if (x < 0 || x > 9) return 1;
    if (y < 0 || y > 19) return 1;
    if (_cells[x][y] != 0) return 1;
  }
  return 0;
}

// __________________________________________________________________
void Structure::removeFullRows() {
  // for (int i = 0; i < 20; i++) {
  int i = 0;
  while (i < 19) {
    bool full_row = true;
    for (int j = 0; j < 10; j++) {
      if (_cells[j][i] == 0) full_row = false;  // one Zero in a row
    }
    if (full_row == true) {
      for (int line = i; line < 19; line++) {
        for (int k = 0; k < 10; k++) {
          _cells[k][line] = _cells[k][line+1];
        }
      }
      for (int k = 0; k < 10; k++) {
        _cells[k][19] = 0;
      }
    } else {
     i++;
    }
  }
}



// __________________________________________________________________
void Structure::show(Tetromino tetromino) {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      printf("\x1b[7m");  // Print inverse
      if (_cells[j][i] == 0) printf("\x1b[0m");
      if (_cells[j][i] == 1) printf("\x1b[31m");
      for (int m = 0; m < Tetromino::_sx; m++) {
        for (int k = 0; k <  Tetromino::_sy; k++) {
          printf("\x1b[%d;%dH ",
          (20 - i) * Tetromino::_sy + k, (1 + j) * Tetromino::_sx + m);
        }
      }
    }
  }
}

// __________________________________________________________________
bool Structure::gameOver() {
  if (_cells[5][19] == 1) return true;
  return false;
}
