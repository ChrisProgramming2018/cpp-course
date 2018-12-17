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
  FRIEND_TEST(AnimationMovieTest, constructor);
  FRIEND_TEST(ActionMovieTest, constructor);
  FRIEND_TEST(MovieTest, constructor);

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
};

// Subclass adding Action related information like rating and director.
class ActionMovie : public Movie {
 public:
  // Constructs a new ActionMovie, uses Movie(...) internally.
  ActionMovie(const std::string title, const int year,
      const std::string director, const std::string rating);
  FRIEND_TEST(ActionMovieTest, constructor);

  ~ActionMovie() {}

  // Returns specific movie information in readable form.
  std::string toString() const;
 private:
  // Movie director.
  std::string _director;
  // Movie rating.
  std::string _rating;
};

class AnimationMovie : public Movie {
 public:
  // also saves the studio
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
