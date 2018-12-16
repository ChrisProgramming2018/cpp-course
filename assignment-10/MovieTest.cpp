// Copyright 2018
// Computer Science
// Autor: Christian Leininger christianleininger@gmx.de


#include <gtest/gtest.h>
#include <string>
#include "./Movie.h"

// Movie
// ____________________________________________________________________________
TEST(MovieTest, constructor) {
  Movie m("MyTitle", 2016);
  ASSERT_STREQ("MyTitle", m._title.c_str());
  ASSERT_EQ(2016, m._year);
}

// ____________________________________________________________________________
TEST(MovieTest, matches) {
  Movie m("MyTitle", 2016);
  ASSERT_FALSE(m.matches("2016"));
  ASSERT_TRUE(m.matches("yti"));
  ASSERT_FALSE(m.matches("yTi"));
  ASSERT_TRUE(m.matches(""));
}

// ____________________________________________________________________________
TEST(MovieTest, getTitle) {
  Movie m("MyTitle", 2016);
  ASSERT_STREQ("MyTitle", m.getTitle().c_str());
}

// ____________________________________________________________________________
TEST(MovieTest, toString) {
  Movie m("MyTitle", 2016);
  ASSERT_STREQ("\"MyTitle\" (2016)", m.toString().c_str());
}
// ActionMovie
TEST(ActionMovieTest, constructor) {
  ActionMovie m("MyTitle", 2016, "Me", "R");
  ASSERT_STREQ("MyTitle", m._title.c_str());
  ASSERT_EQ(2016, m._year);
  ASSERT_STREQ("Me", m._director.c_str());
  ASSERT_STREQ("R", m._rating.c_str());
}
  
TEST(ActionMovieTest, matches) {
  ActionMovie m("MyTitle", 2016, "Me", "R");
  ASSERT_FALSE(m.matches("2016"));
  ASSERT_TRUE(m.matches("yti"));
  ASSERT_FALSE(m.matches("yTi"));
  ASSERT_TRUE(m.matches(""));
}
