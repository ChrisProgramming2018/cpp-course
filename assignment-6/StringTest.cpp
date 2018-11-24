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

// _________________________________________________________
TEST(StringTest, DeepCopy) {
  String s2;
  s2.set("doof");
  String s3(s2);
  s2.set("nicht doof");
  ASSERT_EQ(4, s3._length);
  ASSERT_EQ('d', s3._contents[0]);
  ASSERT_EQ('o', s3._contents[1]);
  ASSERT_EQ('o', s3._contents[2]);
  ASSERT_EQ('f', s3._contents[3]);
}
