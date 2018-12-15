// Copyright 2018
// Computer Sicence
// Autor: Christian Leininger christianleininger@gmx.de

#ifndef ASSIGNMENT_10_MOVIES_H_
#define ASSIGNMENT_10_MOVIES_H_

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "./Movie.h"


class Movies {
 public:
  // deconstructor free memory
  ~Movies();
  // Returns matching movies sorted by title.
  std::vector<Movie*> findMovies(const std::string match) const;
  FRIEND_TEST(MoviesTest, findMovies);

  // parse file into vector
  void readFile(const std::string filename);
  FRIEND_TEST(MoviesTest, readFile);

 private:
  // save all Movie instances
  std::vector<Movie*> _movies;
};
#endif  // ASSIGNMENT_10_MOVIES_H_
