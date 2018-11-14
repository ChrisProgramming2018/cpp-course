// Copyright 2018
// Computer Science
// Author: Christian Leininger

// Includes functions for the google test framework
#include <gtest/gtest.h>
#include "./WhitMonday.cpp"

TEST(WhitMondayTest, calculate) {
  ASSERT_EQ(86, calculate(2015));
  ASSERT_EQ(90, calculate(0));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
