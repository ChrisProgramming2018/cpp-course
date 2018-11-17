// Copyright 2018
// Computer Science
// Author: Christian Leininger ChristianLeininger@gmx.de

#ifndef BLATT_04_TETRIS_H_
#define BLATT_04_TETRIS_H_

// Start position of the tetromino.
extern int tx;
extern int ty;

// Structure for Tetrisfield
extern bool structure[20][10];

// for rotate Teromino Test
extern int txr[4];
extern int tyr[4];

// Initialize screen for ncurses.
void initializeScreen();

// Show tetromino.
void showTetromino(bool showOrDelete, bool collsion);

// Move tetromino.
void moveTetromino(int key, bool reverse);
// does the Tetromino rotate
void rotateTetromino(int n);

// check for collsion with the structure
bool checkCollision();

// to remove full Rows
void removeFullRowsFromStructure();

// add a Teromino to the Structure
bool addTetrominoToStructure();

// Draw the Structure after removing rows
void drawStructure();

// That the Teromino starts always the same, when it on the top
void resetTetromino();

#endif  // BLATT_04_TETRIS_H_
