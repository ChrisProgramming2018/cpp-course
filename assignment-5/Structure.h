// Copyright 2018
// Computer Science 
// Author: Christian Leininger


#ifndef BLATT_05_STRUCTURE_H_
#define BLATT_05_STRUCTURE_H_

#include <gtest/gtest.h>
#include "./Tetromino.h"

// Class for the Structure.
class Structure {
 public:
  // Create empty structure.
  Structure();

  // Add Tetromino to structure.
  void addTetromino(Tetromino tetromino);

  // Check if Tetromino collides with structure or border.
  bool checkCollision(Tetromino tetromino);

  // Identify full rows and remove them from the structure.
  void removeFullRows();

  // Draw current structure (cell filled -> red, not filled -> white).
  void show(Tetromino tetromino);

  // To End the game
  bool gameOver();

 private:
  // One bool for each of the 10 x 20 possible cells.
  int _cells[10][20];

  FRIEND_TEST(StructureTest, checkCollision);
  FRIEND_TEST(StructureTest, removeFullRows);
  FRIEND_TEST(StructureTest, addTetromino);
};

#endif  // BLATT_05_STRUCTURE_H_
