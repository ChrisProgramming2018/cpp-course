// Copyright 2018
// Computer Sience
// Author: Christian Leininger ChristianLeininger@gmx.de

#ifndef BLATT_03_TETRIS_H_
#define BLATT_03_TETRIS_H_

// Position of graviton.
extern int tx;
extern int ty;

// Initialize screen for ncurses.
void initializeScreen();

// Show tetromino.
void showTetromino(bool showOrDelete);

// Move tetromino.
void moveTetromino(int key);



#endif  // BLATT_03_TETRIS_H_
