// Copyright 2018
// Computer Science
// Author: Christian Leininger christianleininger@gmx.de


#include <iostream>
#include <string>
#include "./WordCounter.h"

int main(int argc, int argv) {
  if (argc != 2) {
    std::cout << "Usage : ./WordcounterMain <filename> " << std::endl;
    return 1;
  }
  std::string filname = argv[1];
  WordCounter wordCounter1;
  wordCounter1.readFile(filename);
  wordCounter1.computeWords();
  wordCounter1.computeFrequentWords(10);
}
