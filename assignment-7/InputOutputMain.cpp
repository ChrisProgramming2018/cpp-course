// Copyright 2018
// Computer Science
// Author: Christian Leininger christianleininger@gmx.de


#include <stdio.h>
#include <stdlib.h>
#include "./String.h"
#include "./InputOutput.h"

int main(int argc, char** argv) {
  InputOutput io;
  io.parseCommandLineArguments(argc, argv);
  io.process();
}
