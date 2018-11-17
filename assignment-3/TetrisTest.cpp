// Copyright 2018
// Computer Science
// Author: Christian Leininger Christianleininger@gmx.de

#include <gtest/gtest.h>
#include <ncurses.h>
#include "./Tetris.h"

// _____________________________________________________________________________
TEST(TetrisTest, moveTetromino) {
  tx = 0;
  ty = 0;
  moveTetromino(KEY_DOWN);
  ASSERT_EQ(1, ty);
  ASSERT_EQ(0, tx);
  moveTetromino(KEY_RIGHT);
  ASSERT_EQ(1, ty);
  ASSERT_EQ(1, tx);
}

