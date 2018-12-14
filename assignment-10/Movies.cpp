// Copyright 2018
// Computer Sicence
// Autor: Christian Leininger christianleininger@gmx.de

#include <iostream>
#include <fstreams>
#include <vector>
#include "./Movies.h"

// _____________________________________________________________________________
void Movies::readFile(const std::string filename) {
  std::ifstream file(filename.c_str());
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    exit(1);
  }
  std::string line;
  while (true) {
    std::getline(file, line);
    if (file.eof()) break;
    // Parse line into title, year, popularity.
    std::vector<std::string> token;
    while (true) {
      size_t pos = line.find("\t");
      if (pos == std::string::npos) {
        token.push_back(line);
        break;
      }
      token.push_back(line.substr(0, pos));
      line = line.substr(pos + 1);
    }
    if (token.size() > 4 && token[2] == "Animation") {
      _movies.push_back(new AnimationMovie(
          token[0], atoi(token[1].c_str()), token[4]));
    } else if (token.size() > 5 && token[2] == "Action") {
      _movies.push_back(new ActionMovie(
            token[0], atoi(token[1].c_str()), token[3], token[5]));
    }
  }
}
