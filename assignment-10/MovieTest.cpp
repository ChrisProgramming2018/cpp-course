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
