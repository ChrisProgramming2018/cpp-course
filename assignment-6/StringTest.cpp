// Copyright 2018
// Computer Science
// Author : Christian Leininger Christianleininger@gmx.de

#include <gtest/gtest.h>
#include "./String.h"

// _________________________________________________________
TEST(StringTest, constructor) {
  String s;
  ASSERT_EQ(0, s._length);
  ASSERT_EQ(NULL, s._contents);
}

// _________________________________________________________
TEST(StringTest, set) {
  String s;
  s.set("doof");
  ASSERT_EQ(4, s._length);
  ASSERT_EQ('d', s._contents[0]);
  ASSERT_EQ('o', s._contents[1]);
  ASSERT_EQ('o', s._contents[2]);
  ASSERT_EQ('f', s._contents[3]);
}
