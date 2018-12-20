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

  std::vector<Movie*> yearMovies(const int year) const;
  // get function
  std::vector<Movie*> getMovies() const;
  //  returns the euclidean distance
  int editDistance(const std::string x, const std::string y) const;
 private:
  // save all Movie instances
  std::vector<Movie*> _movies;
};
#endif  // ASSIGNMENT_10_MOVIES_H_
