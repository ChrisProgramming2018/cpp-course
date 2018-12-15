// Copyright 2018
// Computer Science
// Autor: Christian Leininger christianleininger@gmx.de

#include <iostream>
#include <string>
#include <vector>
#include "./Movie.h"
#include "./Movies.h"

// ____________________________________________________________________________
int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: ./MoviesMain <filename>\n");
     exit(1);
  }
  // Read data.
  Movies movies;
  std::cout << "Loading movies ";
  movies.readFile(std::string(argv[1]));
  std::cout << "done." << std::endl;
}
