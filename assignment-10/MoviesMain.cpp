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
  std::cout << "Size of databais is "  << result.size() <<
    " movies" << std::endl;
  std::cout <<
    "File needs to be in format movietitle tab year tab ... " << std::endl;
  while (true) {
    std::string keyWord;
    std::cout << "Type query or \e[1mq\e[0m to exit." << std::endl;
    std::cout << "Type the year to get all movies from that year" << std::endl;
    std::cout << "\e[1m> \e[0m";
    std::getline(std::cin, keyWord);
    if (keyWord == "q") { break; }
    if (!keyWord.empty()
      && keyWord.find_first_not_of("0123456789") == std::string::npos) {
      std::cout << keyWord << std::endl;
      int year = std::stoi(keyWord);
      if (year >= 2020 || year <= 1900) {
        std::cout << "No valid year" << std::endl;
        continue;
      }
      result = movies.yearMovies(year);
      if (result.size() == 0) {
        std::cout << "No movie found with the year" << std::endl;
        continue;
      }
      for (auto& movie : movies.yearMovies(year)) {
        std::cout << movie->toString() << std::endl;
      }
    }
    std::cout << std::endl;
  }
}
