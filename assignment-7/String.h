// Copyright 2018
// Computer Science
// Author: Christian Leininger Christianleininger@gmx.de

#ifndef ASSIGNMENT_7_STRING_H_
#define ASSIGNMENT_7_STRING_H_

#include <gtest/gtest.h>

// Gloal count of the number of objects created.
extern int objectCount;

// A simple string class.
class String {
 public:
  // Constructor (creates an empty string).
  String();
  FRIEND_TEST(StringTest, constructor);

  // Another constructor (so-called copy constructor).
  String(const String& s);

  // Destructor (frees any memory that has been allocated for this object).
  ~String();

  // Set to given string.
  void set(const char* s);
  FRIEND_TEST(StringTest, set);

  // Append a given String to the String s
  void append(const String& s);
  FRIEND_TEST(StringTest, append);

  // Returns part vorm a String
  String substr(int start, int end);
  FRIEND_TEST(StringTest, substr);

  // Returns the same Object only in the reverse order
  void reverse();
  FRIEND_TEST(StringTest, reverse);
  
  // shows on the commandline the reverse order
  void reversePrint();
  FRIEND_TEST(StringTest, reversePrint);

  // Return the length of the string.
  int length() const;

  // The contents (characters) of the string.
  char* _contents;

  // The length of the string (size_t is an unsigned int of the "right" size
  // fort the machine).
  int _length;

  // Id of the object (for demonstrating purposes only).
  int _id;
};

#endif  //   ASSIGNMENT_7_STRING_H_
