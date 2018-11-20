// Copyright 2018
// Computer Science
// Author: Christian Leininger ChristianLeininger@gmx.de

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "./Tetromino.h"

// ________________________________________________
void Tetromino::reset(int kindOfTetromino) {
  _tx = 5;
  _ty = 19;
  switch (kindOfTetromino) {
  // L-teromino
    case 1:
      _txr[0] = -1;
      _txr[1] = -1;
      _txr[2] = 0;
      _txr[3] = 1;
      _tyr[0] = 1;
      _tyr[1] = 0;
      _tyr[2] = 0;
      _tyr[3] = 0;
      break;
  // the other L - tetromino
    case 2:
      _txr[0] = 0;
      _txr[1] = 0;
      _txr[2] = -1;
      _txr[3] = -2;
      _tyr[0] = 0;
      _tyr[1] = 1;
      _tyr[2] = 1;
      _tyr[3] = 1;
      break;
  // shape of z
    case 3:
      _txr[0] = 0;
      _txr[1] = 0;
      _txr[2] = 1;
      _txr[3] = -1;
      _tyr[0] = 0;
      _tyr[1] = 1;
      _tyr[2] = 1;
      _tyr[3] = 0;
      break;
  // shape of s
    case 4:
      _txr[0] = 0;
      _txr[1] = 0;
      _txr[2] = 1;
      _txr[3] = -1;
      _tyr[0] = 0;
      _tyr[1] = 1;
      _tyr[2] = 0;
      _tyr[3] = 1;
      break;
  // shape of t
    case 5:
      _txr[0] = 0;
      _txr[1] = 0;
      _txr[2] = 1;
      _txr[3] = -1;
      _tyr[0] = 0;
      _tyr[1] = -1;
      _tyr[2] = 0;
      _tyr[3] = 0;
      break;
  // shape of I
    case 6:
      _txr[0] = 0;
      _txr[1] = 0;
      _txr[2] = 0;
      _txr[3] = 0;
      _tyr[0] = 0;
      _tyr[1] = -1;
      _tyr[2] = -2;
      _tyr[3] = -3;
      break;
  // quader
    case 7:
      _txr[0] = 1;
      _txr[1] = 1;
      _txr[2] = 0;
      _txr[3] = 0;
      _tyr[0] = 1;
      _tyr[1] = 0;
      _tyr[2] = 1;
      _tyr[3] = 0;
      break;
  }
}

// _______________________________________________________
void Tetromino::move(int key, bool reverse) {
  switch (key) {
    case KEY_UP:
      if (reverse == false) Tetromino::rotate(1);
      if (reverse == true) Tetromino::rotate(3);
      break;
    case KEY_DOWN:
      if (reverse == false) _ty--;
      if (reverse == true)  _ty++;
      break;
    case KEY_RIGHT:
      if (reverse == false) _tx++;
      if (reverse == true)  _tx--;
      break;
    case KEY_LEFT:
      if (reverse == false) _tx--;
      if (reverse == true)  _tx++;
      break;
  }
}

// _______________________________________________________
void Tetromino::rotate(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      int xx  = _tyr[j];
      int yy  = -_txr[j];
      _txr[j]  = xx;
      _tyr[j]  = yy;
    }
  }
}

// _______________________________________________________
void Tetromino::show(bool showOrDelete, bool bottomReached) {
  if (showOrDelete == true) printf ("\x1b[7m");  // Print inverse
  if (bottomReached == true) printf ("\x1b[1m");  // Red
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < _sx; j++) {
      for (int k = 0; k < _sy; k++) {
        printf("\x1b[%d;%dH ",
          (20 - _ty - _tyr[i]) * _sy + k, (1 + _tx + _txr[i]) * _sx + j);
      }
    }
  }
  printf("\x1b[0m");
  if (showOrDelete == true) fflush(stdout);
}
