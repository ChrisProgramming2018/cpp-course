// Copyright 2018
// Computer Science
// Author: Christian Leininger christianleininger@gmx.de

#ifndef ASSIGNMENT_9_WORDCOUNTER_H_
#define ASSIGNMENT_9_WORDCOUNTER_H_

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class Wordcounter {
 public:
  // save the every line from the given file
  // in the vector
  void readFile(std::string filename);

  // fills the hash table key:word, data:amount
  void computeWords();

  //
  void computeFrequentWords(int number);

  //
  std::vector<std::string> _words;

  //
  std::unordered_map<std::string, int> _mapWordCounter;
};

#endif  //  ASSIGNMENT_9_WORDCOUNTER_H_
