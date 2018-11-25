// Copyright
// Computer Science 
// Author: Christian Leininger christianleininger@


#include <stdio.h>
#include <stdlib.h>
#include <getop.h>
#include <iostream>
#include "./String.h"
#include "./InputOutput.h"

// ________________________________________________________
InputOutput::InputOutput() {
  _palindromes = false;
}

// ________________________________________________________
void InputOutput::parseCommandLineArguments(int argc, char** argv) {
  struct option options [] = {
    { "--palindroms-only", 0, NULL, 'p'},
    { NULL, 0, NULL, 0 }
  };
  optind = 1;
  while (true) {
    char c = getopt_longi(argc, argv, "p", options, NULL);
    std::cout << c << std::endl;
    if ( c== -1) break;
    if ( c== '?') { exit(1)};
    if ( c== 'p') _palendromes = true;
  }
  if ( optind + 1 != argc) {
    fprintf(stderr, "Usage: ./InputOutputMain <filename>\n");
    exit(1);
  }
  _filename = argv[optind];
}

