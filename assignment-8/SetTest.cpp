// Copyright 2018
// Computer Science
// Author: Christian Leininger christianleininger@gmx.de


#include <gtest/gtest.h>
#include "./Set.h"

// ____________________________________________________________________________
TEST(SetTest, constructorT) {
  Set<int> set;
  ASSERT_EQ(0, set._size);
}

// ____________________________________________________________________________
TEST(SetTest, insertT) {
  Set<int> set;
  ASSERT_EQ(0, set._size);
  set.insert(0);
  ASSERT_EQ(1, set._size);
  ASSERT_EQ(0, set._elements[0]);

  set.insert(0);
  ASSERT_EQ(1, set._size);
  ASSERT_EQ(0, set._elements[0]);

  set.insert(2);
  ASSERT_EQ(2, set._size);
  ASSERT_EQ(0, set._elements[0]);
  ASSERT_EQ(2, set._elements[1]);

  set.insert(1);
  ASSERT_EQ(3, set._size);
  ASSERT_EQ(0, set._elements[0]);
  ASSERT_EQ(2, set._elements[1]);
  ASSERT_EQ(1, set._elements[2]);
}

// ____________________________________________________________________________
TEST(SetTest, removeT) {
  Set<int> set;
  set.insert(0);
  set.insert(0);
  set.insert(1);
  set.insert(2);
  ASSERT_EQ(3, set._size);
  ASSERT_EQ(0, set._elements[0]);
  ASSERT_EQ(1, set._elements[1]);
  ASSERT_EQ(2, set._elements[2]);

  set.remove(0);
  ASSERT_EQ(2, set._size);
  ASSERT_EQ(1, set._elements[0]);
  ASSERT_EQ(2, set._elements[1]);

  set.remove(0);
  ASSERT_EQ(2, set._size);
  ASSERT_EQ(1, set._elements[0]);
  ASSERT_EQ(2, set._elements[1]);

  set.remove(1);
  ASSERT_EQ(1, set._size);
  ASSERT_EQ(2, set._elements[0]);
}

// ____________________________________________________________________________
TEST(SetTest, findT) {
  Set<int> set;
  ASSERT_FALSE(set.find(0));
  ASSERT_FALSE(set.find(1));

  set.insert(0);
  ASSERT_TRUE(set.find(0));
  ASSERT_FALSE(set.find(1));

  set.insert(1);
  ASSERT_TRUE(set.find(0));
  ASSERT_TRUE(set.find(1));

  set.remove(0);
  ASSERT_TRUE(set.find(1));
  ASSERT_FALSE(set.find(0));
}

// ____________________________________________________________________________
TEST(SetTest, constructorChar) {
  Set<char> set;
  for (size_t  i = 0; i < 256; i++) {
    ASSERT_FALSE(set._elements[i])<< "Error at i=" << i;
  }
}

// ____________________________________________________________________________
TEST(SetTest, insertChar) {
  Set<char> set;
  for (size_t i = 0; i < 256; i++) {
    ASSERT_FALSE(set._elements[i]) << "Error at i=" << i;
  }
  set.insert('a');
  for (size_t i = 0; i < 256; i++) {
    if (i != 'a') {
      ASSERT_FALSE(set._elements[i]) << "Error at i=" << i;
    }
  }
  ASSERT_TRUE(set._elements['a']);
  set.insert('a');
  for (size_t i = 0; i < 256; i++) {
    if (i != 'a') {
      ASSERT_FALSE(set._elements[i]) << "Error at i=" << i;
    }
  }
  ASSERT_TRUE(set._elements['a']);
  set.insert('b');
  for (size_t i = 0; i < 256; i++) {
    if (i != 'a' && i != 'b') {
      ASSERT_FALSE(set._elements[i]) << "Error at i=" << i;
    }
  }
  ASSERT_TRUE(set._elements['a']);
  ASSERT_TRUE(set._elements['b']);
}
