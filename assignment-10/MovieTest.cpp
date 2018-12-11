// Copyright 2018
// Computer Science
// Autor: Christian Leininger christianleininger@gmx.de


#include <gtest/gtest.h>
#include <string>
#include "./Movie.h"

// Movie
TEST(MovieTest, constructor) {
  Movie m("MyTitle", 2016);
  ASSERT_STREQ("MyTitle", m._title.c_str());
  ASSERT_EQ(2016, m._year);
}
