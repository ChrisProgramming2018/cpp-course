// Copyright 2018
// Computer Science
// Autor: Christian Leininger christianleininger@gmx.de


#include <gtest/gtest.h>
#include <string>
#include "./Movie.h"
#include "./Movies.h"

TEST(MoviesTest, readFile) {
  FILE* input = fopen("MoviesTest.tmp", "w");
  fprintf(input, "Movie4\t2014\tAnimation\tPerson\tPixar\tRating\n"
      "Movie2\t2012\tAction\tGeorge Lukas\tStudio\tPG13\n"
      "Movie3\t2013\tAnimation\tPerson\tLong studio with many characters"
      "\tRatring\nMovie1\t2011\tAction\tGeorge Lukas\tStudio\tR\n"
      "Invalid\t2015\tAction\tDirector\tStudio\n"
      "Another\t2016\tAnimation\tDirector\n");
  fclose(input);

  Movies mi;
  ASSERT_EQ(0, mi._movies.size());
  mi.readFile(std::string("MoviesTest.tmp"));
  ASSERT_EQ(4, mi._movies.size());
  ASSERT_STREQ("\"Movie4\" (2014), produced by Pixar",
      mi._movies[0]->toString().c_str());
  ASSERT_STREQ("\"Movie2\" (2012), directed by George Lukas, rated: PG13",
      mi._movies[1]->toString().c_str());
  ASSERT_STREQ(
      "\"Movie3\" (2013), produced by Long studio with many characters",
      mi._movies[2]->toString().c_str());
  ASSERT_STREQ("\"Movie1\" (2011), directed by George Lukas, rated: R",
      mi._movies[3]->toString().c_str());
  unlink("MoviesTest.tmp");
}

TEST(MoviesTest, findMovies) {
  Movies mi;
  mi._movies.push_back(new ActionMovie(
        "Movie2", 2012, "George Lukas", "PG13"));
  mi._movies.push_back(new AnimationMovie( "Movie4", 2014, "Pixar"));
  mi._movies.push_back(new ActionMovie("Movie1", 2011, "George Lukas", "R"));
  mi._movies.push_back(new AnimationMovie(
        "Movie3", 2013, "Long studio with many characters"));
  ASSERT_EQ(4, mi._movies.size());
}
