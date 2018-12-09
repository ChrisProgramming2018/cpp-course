// Copyright 2018
// Computer Sicence
// Autor: Christian Leininger christianleininger@gmx.de

#ifndef ASSIGNMENT_10_MOVIE_H_
#define ASSIGNMENT_10_MOVIE_H_

#include <gtest/gtest.h>
#include <string>
class Movie {
 public:
  Movie(const std::string title, const int year);

  // frees the memory
  virtual ~Movie() {}

  bool match(const std::string  pointer) const;

  // show inforamtion readable form
  virtual std::string toString() const;

 private:
  // Movie title
  std::string _title;

  // year of release
  int _year;
};

#endif  // ASSIGNMENT_10_MOVIE_H_
