// Copyright 2018
// Computer Science
// Author: Christian Leininger Christianleininger@gmx.de

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include "./Tetris.h"
#include "./Tetromino.h"

// __________________________________________________________________
Tetris::Tetris() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);
}

// __________________________________________________________________
Tetris::~Tetris() {
  endwin();
}

// __________________________________________________________________
void Tetris::play() {
  _tetromino.reset((lrand48() % 7) + 1);
  _tetromino.show(true, false);
  int key;
  int timer = 0;
  bool collision = false;
  bool gameOver = false;
  while (true) {
    key = getch();
    if (++timer % 100 == 0) key = KEY_DOWN;
    moveIfPossible(key);
    checkBottomReached();
    usleep(10 * 1000);
    // To end the game
    gameOver = _structure.gameOver();
    if (gameOver) break;
  }
}


// __________________________________________________________________
void Tetris::moveIfPossible(int key) {
  _tetromino.show(false, false);  // don't show in old position
  _tetromino.move(key, false);  // move according to key
  bool collision = _structure.checkCollision(_tetromino);
  if (collision) _tetromino.move(key, true);  // move back if  collision
  _tetromino.show(true, false);  // show in new collision
}


// __________________________________________________________________
void Tetris::checkBottomReached() {
  _tetromino.move(KEY_DOWN, false);  // just for checking...
  bool collision = _structure.checkCollision(_tetromino);
  _tetromino.move(KEY_DOWN, true);  // move back in every case
if (collision) {
    _structure.addTetromino(_tetromino);
    _structure.removeFullRows();
    _structure.show(_tetromino);
    _tetromino.reset((lrand48() % 7) + 1);
    _tetromino.show(true, false);
  }
}

