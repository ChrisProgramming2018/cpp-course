// Copyright 2018
// Computer Science
// Author: Christian Leininger ChristianLeininger@gmx.de

#include <gtest/gtest.h>
#include <ncurses.h>
#include "./Structure.h"
#include "./Tetris.h"
#include "./Tetromino.h"

// _____________________________________________________________________________
TEST(TetrisTest, move) {
  Tetromino tetromino;
  tetromino.reset(1);
  tetromino._tx = 3;
  tetromino._ty = 10;
  tetromino.move(KEY_LEFT, false);
  ASSERT_EQ(2, tetromino._tx);
  ASSERT_EQ(10, tetromino._ty);
  tetromino.move(KEY_RIGHT, false);
  ASSERT_EQ(3, tetromino._tx);
  ASSERT_EQ(10, tetromino._ty);
  tetromino.move(KEY_DOWN, false);
  ASSERT_EQ(3, tetromino._tx);
  ASSERT_EQ(9, tetromino._ty);
  tetromino.move(KEY_DOWN, true);
  ASSERT_EQ(3, tetromino._tx);
  ASSERT_EQ(10, tetromino._ty);
}

// _____________________________________________________________________________
  TEST(TetrisTest, rotate) {
  Tetromino tetromino;
  tetromino._txr[0] = -1;
  tetromino._txr[1] = 0;
  tetromino._txr[2] = 1;
  tetromino._txr[3] = 1;
  tetromino._tyr[0] = -1;
  tetromino._tyr[1] = -1;
  tetromino._tyr[2] = -1;
  tetromino._tyr[3] = 0;
  tetromino.rotate(1);
  ASSERT_EQ(-1, tetromino._txr[0]);
  ASSERT_EQ(-1, tetromino._txr[1]);
  ASSERT_EQ(-1, tetromino._txr[2]);
  ASSERT_EQ(0, tetromino._txr[3]);
  ASSERT_EQ(1, tetromino._tyr[0]);
  ASSERT_EQ(0, tetromino._tyr[1]);
  ASSERT_EQ(-1, tetromino._tyr[2]);
  ASSERT_EQ(-1, tetromino._tyr[3]);
  tetromino.rotate(3);
  ASSERT_EQ(-1, tetromino._txr[0]);
  ASSERT_EQ(0, tetromino._txr[1]);
  ASSERT_EQ(1, tetromino._txr[2]);
  ASSERT_EQ(1, tetromino._txr[3]);
  ASSERT_EQ(-1, tetromino._tyr[0]);
  ASSERT_EQ(-1, tetromino._tyr[1]);
  ASSERT_EQ(-1, tetromino._tyr[2]);
  ASSERT_EQ(0, tetromino._tyr[3]);
}

// _____________________________________________________________________________
TEST(TetrisTest, reset) {
  Tetromino tetromino;
  tetromino._txr[0] = 0;
  tetromino._txr[1] = 0;
  tetromino._txr[2] = 0;
  tetromino._txr[3] = 0;
  tetromino._tyr[0] = 0;
  tetromino._tyr[1] = 0;
  tetromino._tyr[2] = 0;
  tetromino._tyr[3] = 0;
  tetromino.reset(1);
  ASSERT_EQ(-1, tetromino._txr[0]);
  ASSERT_EQ(-1, tetromino._txr[1]);
  ASSERT_EQ(0, tetromino._txr[2]);
  ASSERT_EQ(1, tetromino._txr[3]);
  ASSERT_EQ(1, tetromino._tyr[0]);
  ASSERT_EQ(0, tetromino._tyr[1]);
  ASSERT_EQ(0, tetromino._tyr[2]);
  ASSERT_EQ(0, tetromino._tyr[3]);
  tetromino.reset(3);
  ASSERT_EQ(0, tetromino._txr[0]);
  ASSERT_EQ(0, tetromino._txr[1]);
  ASSERT_EQ(1, tetromino._txr[2]);
  ASSERT_EQ(-1, tetromino._txr[3]);
  ASSERT_EQ(0, tetromino._tyr[0]);
  ASSERT_EQ(1, tetromino._tyr[1]);
  ASSERT_EQ(1, tetromino._tyr[2]);
  ASSERT_EQ(0, tetromino._tyr[3]);
}
