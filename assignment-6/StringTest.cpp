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

// _________________________________________________________
TEST(StringTest, append) {
  String s;
  s.set("Computer");
  String s2;
  s2.set(" Science");
  s.append(s2);
  ASSERT_EQ('C', s._contents[0]);
  ASSERT_EQ('o', s._contents[1]);
  ASSERT_EQ('m', s._contents[2]);
  ASSERT_EQ('p', s._contents[3]);
  ASSERT_EQ('u', s._contents[4]);
  ASSERT_EQ('t', s._contents[5]);
  ASSERT_EQ('e', s._contents[6]);
  ASSERT_EQ('r', s._contents[7]);
  ASSERT_EQ(' ', s._contents[8]);
  ASSERT_EQ('S', s._contents[9]);
  ASSERT_EQ('c', s._contents[10]);
  ASSERT_EQ('i', s._contents[11]);
  ASSERT_EQ('e', s._contents[12]);
  ASSERT_EQ('n', s._contents[13]);
  ASSERT_EQ('c', s._contents[14]);
  ASSERT_EQ('e', s._contents[15]);
}
