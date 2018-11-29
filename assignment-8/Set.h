// Copyright 2018
// Computer Science
// Author: Christian Leininger christianleininger@gmx.de

#ifndef ASSIGNMENT_8_SET_H_
#define ASSIGNMENT_8_SET_H_

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

  // returns True if element is found
  bool find(T n);

  //
  int getSize();
};

// A
template<>
class Set<char> {
 public:
  // variable to save size
  int _size;

  // constructor for char
  char* _elements;

  //
  Set();

  //
  ~Set();

  // insert char
  void insert(char n);

  void erase(char n);

  bool find(char n);
};

#endif  // ASSIGNMENT_8_SET_H_
