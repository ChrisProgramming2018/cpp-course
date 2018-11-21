// Copyright 2018
// Computer Science
// Author: Christan Leininger christianleininger@gmx.de

#include <stdio.h>
#include "./Tetris.h"

// Main function.
int main(int argc, char** argv) {
  Tetris tetris;
  tetris.play();
  tetris.~Tetris();
}

