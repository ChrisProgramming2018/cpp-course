// Copyright 2018
// Computer Science
// Author: Christian Leininger christianleininger@gmx.de

#include "./WordCounter.h"
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
  std::ifstream file(fileName.c_str());
  // error if there is no file 
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    exit(1);
  }
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
      if (begin == string::npos) break;
      line = line.substr(begin, endline);
      end = line.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
      if (end == string::npos) {
        end = line.find_last_of("abcdefghijklmnopqrstuvwxyz");
        end++;
      }
      wordsize = end - begin;
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
  for (auto& x : _words) {
    _mapWordCounter[x]++;
  }
}

// ____________________________________________________________________________
std::vector<std::pair<std::string, size_t>> WordCounter::computeFrequentWords(int number) {
  std::vector<std::pair<std::string, size_t>> result;
  for (auto& items : _mapWordCounter) {
    result.push_back(std::pair<std::string, size_t>(items.first, items.second));
  }
  // use lambda expression to sort
  std::sort(result.begin(), result.end(), [] (
        const std::pair<std::string, size_t> &left, 
        const std::pair<std::string, size_t> &right) {
      return left.second > right.second;
      });
  result.resize(std::min(number, result.size()));
  return result;
}
