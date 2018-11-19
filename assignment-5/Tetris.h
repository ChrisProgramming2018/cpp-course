// Copyright 2018
// Computer Science 
// Author: Christian Leininger ChristianLeininger@gmx.de

#include "./Structure.h"

#ifndef BLATT_05_TETRIS_H_
#define BLATT_05_TETRIS_H_

// Class for the Tetris game.
class Tetris {
 public:
  // Prepare terminal.
  Tetris();

  // Clean up terminal.
  ~Tetris();

  // Play the game.
  void play();

  // Move Tetromino according to key, if there is no collision.
  void moveIfPossible(int key);

  // If Bottom is reached, add Tetromino to structure, show Structure
  // and reset Tetromino
  void checkBottomReached();

  // Needed in Tetris.cpp
  Structure _structure;
  Tetromino _tetromino;
};
#endif  // BLATT_05_TETRIS_H_
