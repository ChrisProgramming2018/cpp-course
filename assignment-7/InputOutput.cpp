// Copyright
// Computer Science
// Author: Christian Leininger christianleininger@

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "./String.h"
#include "./InputOutput.h"

// ________________________________________________________
InputOutput::InputOutput() {
  _palindromes = false;
}

// ________________________________________________________
void InputOutput::parseCommandLineArguments(int argc, char** argv) {
  struct option options[] = {
    { "--palindromes-only", 0, NULL, 'p'},
    { NULL, 0, NULL, 0 }
  };
  optind = 1;
  while (true) {
    char c = getopt_long(argc, argv, "p", options, NULL);
    if (c == -1) break;
    if (c == '?') { exit(1); }
    if (c == 'p') _palindromes = true;
  }
  if (optind + 1 != argc) {
    fprintf(stderr, "Usage: ./InputOutputMain <filename>\n");
    fprintf(stderr, "--with-line-numbers / -l : print with line numbers\n");
    exit(1);
  }
  _filename = argv[optind];
}

// ________________________________________________________
void InputOutput::process() {
  FILE* file = fopen(_filename, "r");
  if (file == NULL) { perror("InputOutput::process"); exit(1); }
  int lineNumber = 0;
  int lengthOfLine = 0;
  int maxLineLength = 1000;
  char* line = new char[maxLineLength + 1];
  bool theSame = true;
  String s;
  String result;
  while (true) {
    fgets(line, maxLineLength + 1, file);
    if (feof(file)) break;
    if (_palindromes) {
      s.set(line);
      lengthOfLine = s.length();
      s.substr(0, lengthOfLine - 1, &result);
      result.reverse();
      theSame = true;
      for (int i = 0; i < lengthOfLine - 1; i++) {
        if (!(result._contents[i] == s._contents[i])) {
          theSame = false;
        }
      }
      if (theSame) {
        result.reversePrint();
      }
    } else {
      s.set(line);
      lengthOfLine = s.length();
      s.substr(0, lengthOfLine -1, &result);
      result.reversePrint();
    }
  }
  fclose(file);
  delete[] line;
}
