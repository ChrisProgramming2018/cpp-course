// Copyright
// Computer Science 
// Author: Christian Leininger christianleininger@


#include <stdio.h>
#include <stdlib.h>
#include <getop.h>
#include "./String.h"
#include "./InputOutput.h"

// ________________________________________________________
InputOutput::InputOutput() {
  _palindromes = false;
}

// ________________________________________________________
void InputOutput::parseCommandLineArguments(int argc, char** argv) {
  struct option options [] = { 
