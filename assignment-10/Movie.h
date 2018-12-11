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
  
  // 
  std::string getTitle() const;
 private:
  // Movie title
  std::string _title;

  // year of release
  int _year;
};

// Subclass

class ActionMovie : public Movie {
 public:
  // construct a instance
  ActionMovie(const std::string, const int year, 
      const std::string, director, const std::string rating);
 private:

};
#endif  // ASSIGNMENT_10_MOVIE_H_
