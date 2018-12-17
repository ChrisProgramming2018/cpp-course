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
  std::vector<Movie*> result;
  result = movies.getMovies();
  std::cout <<"Size of databais is "  << result.size() <<" movies" <<std::endl;
  std::cout <<"File needs to be in format movietitle tab year tab ... " <<std::endl;
  for (auto& movie : movies._movies) {
      // std::cout << movie->getTitle() << std::endl;
      //std::cout << movie->toString() << std::endl;
  }
  while (true) {
    std::string keyWord;
    std::cout << "Type query or \e[1mquit\e[0m to exit." << std::endl;
    std::cout << "\e[1m> \e[0m";
    std::getline(std::cin, keyWord);
    if (keyWord == "quit") { break; }
    for (auto& movie : movies.findMovies(keyWord)) {
      std::cout << movie->toString() << std::endl;
    }
    std::cout << std::endl;
  }
}
