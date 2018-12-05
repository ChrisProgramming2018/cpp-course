// Copyright 2018
// Computer Science
// Author: Christian Leininger christianleininger@gmx.de

#include "./Wordcounter.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>

using std::vector;
using std::string;
using std::iostream;
using std::fstream;

// ____________________________________________________________________________
void WordCounter::readFile(std::string fileName) {
  std::ifstream file(fileName.cstr());
  string line;
  while (true) {
    getline(file, line);
    if (file.eof()) break;
    std::transform(line.begin(), line.end(), line.begin(), tolower);
    size_t endline = line.find("\n");
    size_t begin = 0;
    size_t end = 0;
    size_t wordsize = 0;
    while (true) {
      begin = line.find_first_of("abcdefghijklmnopqrstuvwxyz");
      // if there is no char go to nextline
      if (begin == string::nopos) break;
      line = line.substr(bgein, endline);
      end = line.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
      if (end == string::nopos) {
        end = line.find_last_of("abcdefghijklmnopqrstuvwxyz");
        end++;
      }
      wordsize = end -start;
      string word = line.substr(0, end);
      if (wordsize > 4) {
        _words.push_back(word);
      }
      line = line.substr(end, endline);
    }
  }
  file.close();
}

// ____________________________________________________________________________
void WordCounter::computeWords() {
  for (auto& x : words) {
    _mapWordCounter[x]++;
  }
}

// ____________________________________________________________________________
void WordCounter::computeFrequentWords() {
}
