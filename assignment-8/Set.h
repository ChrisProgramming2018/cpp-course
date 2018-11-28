// Copyright 2018
// Computer Science
// 

#ifndef
#define

#include <gtest/gtest.h>

template<class T>
class Set {
 private:
  int _size;

  T* _elements;

  FRIEND_TEST(SetTest, constructorT);
  FRIEND_TEST(SetTest, insertT);
  FRIEND_TEST(SetTest, eraseT);
  FRIEND_TEST(SetTest, findT);
 
 public:
  // Constructor
  Set();

  // Deconstructor
  ~Set();

  // Add the given Element n to the Set
  void insert(T n);

  // Remove given Element from Set
  void remove(T n);
}
