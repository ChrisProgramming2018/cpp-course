// Copyright 2018
// Computer Science
// Author: Christian Leininger Christianleininger@gmx.de


#ifndef ASSIGNMENT_5_TETROMINO_H_
#define ASSIGNMENT_5_TETROMINO_H_

#include <gtest/gtest.h>

// Class for a single Tetromino.
class Tetromino {
 public:
  // Reset Tetromino to given kind in starting position at the top.
  void reset(int kindOfTetromino);

  // Move Tetromino according to last key. If reverse == true, do the opposite.
  void move(int key, bool reverse);
  // FRIEND_TEST(TetrisTest, move);

  // Rotate Tetromino by n times 90 degrees clockwise.
  void rotate(int n);
  // FRIEND_TEST(TetrisTest, rotate);

  // Show Tetromino at current position. If showOrDelete == true, draw in
  // inverse video, otherwise draw spaces to delete it. If bottomReached, draw
  // in red.
  void show(bool showOrDelete, bool bottomReached);

 private:
  friend class Structure;
  // Stretch of a pixel;
  static const  int _sx = 5;
  static const  int _sy = 3;

  // Absolute position of the Tetromino.
  int _tx;
  int _ty;

  // Relative positions of the four parts of the Tetromino.
  int _txr[4];
  int _tyr[4];

  FRIEND_TEST(TetrisTest, move);
  FRIEND_TEST(TetrisTest, rotate);
  FRIEND_TEST(TetrisTest, reset);
  FRIEND_TEST(StructureTest, addTetromino);
  FRIEND_TEST(StructureTest, checkCollision);
};
#endif  // ASSIGNMENT_5_TETROMINO_H_
