// Copyright 2018
// Computer Sicence
// Autor: Christian Leininger christianleininger@gmx.de

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "./Movie.h"
#include "./Movies.h"

// _____________________________________________________________________________
Movies::~Movies() {
  for (auto& movie : _movies) { delete movie; }
  _movies.clear();
}
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
      size_t pos = line.find('\t');
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

// _____________________________________________________________________________
std::vector<Movie*> Movies::findMovies(std::string match) const {
  std::vector<Movie*> result;
  std::transform(match.begin(), match.end(), match.begin(), ::tolower);
  result.clear();
  for (auto& movie : _movies) {
    if (movie->matches(match)) { result.push_back(movie); }
  }
  std::sort(result.begin(), result.end(), [](
        Movie* left,
        Movie* right) {
      return left->getTitle() < right->getTitle();
      });
  return result;
}

// _____________________________________________________________________________
std::vector<Movie*> Movies::yearMovies(const int year) const {
  std::vector<Movie*> result;
  for (auto& movie : _movies) {
    if (movie->getYear() == year) {result.push_back(movie);}
  }
  return result;
}
// _____________________________________________________________________________
std::vector<Movie*> Movies::getMovies() const {
  return _movies;
}

// _____________________________________________________________________________
int Movies::editDistance(const std::string x, const std::string y) const {
  int **xArray = new int*[x.size()];
  // int *yArray = new int[y.size()];
  for (int i=0; i <= x.size(); i++) {
    xArray[i] = new int[y.size()];
  }
  for (int i=0; i <= x.size()+1; i++) {
    for (int j=0; j <= x.size()+1; j++) {
      if (i == 0) {xArray[i][j] = j;} 
      if (j == 0) {xArray[i][j] = i;}
      std::cout << xArray[i][j];
    }
    std::cout << std::endl;
  }
  for (int i=1; i <= x.size()+1; i++) {
    for (int j=1; j <= x.size()+1; j++) {
      std::cout << x.at(i) << std::endl;
    }
  }
  // free memory
  for (int i=0; i <= x.size(); i++) {
    delete [] xArray[i];
  }

  delete [] xArray;
}
