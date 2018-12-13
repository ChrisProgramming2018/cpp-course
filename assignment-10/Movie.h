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

  bool matches(const std::string  match) const;

  // show inforamtion readable form
  virtual std::string toString() const;

  //
  std::string getTitle() const;
 private:
  // Movie title
  std::string _title;

  // year of release
  int _year;
  FRIEND_TEST(AnimationMovieTest, constructor);
  FRIEND_TEST(ActionMovieTest, constructor);
  FRIEND_TEST(MovieTest, constructor);
};

// Subclass

class ActionMovie : public Movie {
 public:
  // construct a instance
  ActionMovie(const std::string, const int year,
      const std::string director, const std::string rating);

  // frees memory
  ~ActionMovie();

  //
  std::string toString() const;

 private:
  // Movie
  std::string _director;

  // Movie rating
  std::string _rating;
};

class AnimationMovie : public Movie {
 public:
  //
  AnimationMovie(const std::string title, const int year,
      const std::string studio);
  FRIEND_TEST(AnimationMovieTest, constructor);

  // free momory
  ~AnimationMovie() {}

  std::string toString() const;
 private:
  std::string _studio;
};

#endif  // ASSIGNMENT_10_MOVIE_H_
