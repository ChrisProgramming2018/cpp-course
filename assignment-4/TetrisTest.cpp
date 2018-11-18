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
  moveTetromino(KEY_DOWN, false);
  ASSERT_EQ(1, ty);
  ASSERT_EQ(0, tx);
  moveTetromino(KEY_RIGHT, false);
  ASSERT_EQ(1, ty);
  ASSERT_EQ(1, tx);
  moveTetromino(KEY_DOWN, true);
  ASSERT_EQ(0, ty);
  ASSERT_EQ(1, tx);
  moveTetromino(KEY_RIGHT, true);
  ASSERT_EQ(0, ty);
  ASSERT_EQ(0, tx);
}

// _____________________________________________________________________________
TEST(TetrisTest, checkCollision) {
  tx = 5;
  ty = 15;
  txr[0]= 0;
  txr[1]= 1;
  txr[2]= -1;
  txr[3]= -1;
  tyr[0]= 0;
  tyr[1]= 0;
  tyr[2]= 0;
  tyr[3]= -1;
  checkCollision();
  ASSERT_EQ(false, checkCollision());
  tx = 15;
  ASSERT_EQ(true, checkCollision());
}

// _____________________________________________________________________________
TEST(TetrisTest, rotateTetromino) {
  txr[0]= 0;
  txr[1]= 1;
  txr[2]= -1;
  txr[3]= -1;
  tyr[0]= 0;
  tyr[1]= 0;
  tyr[2]= 0;
  tyr[3]= -1;
  rotateTetromino(1);
  ASSERT_EQ(0, txr[0]);
  ASSERT_EQ(0, txr[1]);
  ASSERT_EQ(0, txr[2]);
  ASSERT_EQ(1, txr[3]);
  ASSERT_EQ(0, tyr[0]);
  ASSERT_EQ(1, tyr[1]);
  ASSERT_EQ(-1, tyr[2]);
  ASSERT_EQ(-1, tyr[3]);
}

// _____________________________________________________________________________
TEST(TetrisTest, removeFullRowsFromStructure) {
  structure[20][10];
  structure[17][0] = false;
  structure[17][1] = false;
  structure[17][2] = false;
  structure[17][3] = false;
  structure[17][4] = false;
  structure[17][5] = false;
  structure[17][6] = false;
  structure[17][7] = false;
  structure[17][8] = false;
  structure[17][9] = false;
  structure[18][0] = true;
  structure[18][1] = true;
  structure[18][2] = true;
  structure[18][3] = true;
  structure[18][4] = true;
  structure[18][5] = true;
  structure[18][6] = true;
  structure[18][7] = true;
  structure[18][8] = true;
  structure[18][9] = true;
  removeFullRowsFromStructure();
  ASSERT_EQ(false, structure[18][0]);
  ASSERT_EQ(false, structure[18][1]);
  ASSERT_EQ(false, structure[18][2]);
  ASSERT_EQ(false, structure[18][3]);
  ASSERT_EQ(false, structure[18][4]);
  ASSERT_EQ(false, structure[18][5]);
  ASSERT_EQ(false, structure[18][6]);
  ASSERT_EQ(false, structure[18][7]);
  ASSERT_EQ(false, structure[18][8]);
  ASSERT_EQ(false, structure[18][9]);
}

// _____________________________________________________________________________
TEST(TetrisTest, addTetrominoToStructure) {
  tx = 0;
  ty = 10;
  txr[0]= 0;
  txr[1]= 1;
  txr[2]= 2;
  txr[3]= 3;
  tyr[0]= 0;
  tyr[1]= 0;
  tyr[2]= 0;
  tyr[3]= 0;
  structure[20][10];
  structure[10][0] = false;
  structure[10][1] = false;
  structure[10][2] = false;
  structure[10][3] = false;
  addTetrominoToStructure();
  ASSERT_EQ(true, structure[10][0]);
  ASSERT_EQ(true, structure[10][1]);
  ASSERT_EQ(true, structure[10][2]);
  ASSERT_EQ(true, structure[10][3]);
}
