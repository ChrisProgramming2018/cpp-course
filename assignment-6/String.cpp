// Copyright 2018
// Computer Science
// Author: Christian Leininger Christianleininger@gmx.de

#include <stdio>
#include "./String.h"

// ________________________________________________________
String::String() {
  _contents = NULL;
  _length = 0;
}

// ________________________________________________________
String::String(const String& s) {
  _length = s._length;
  _contents = new char[_length];
  for (int i = 0; i < _length; i++) {
    _contents[i] = s.contents[i];
  }
}

// ________________________________________________________
String::~String() {
  delete[] _contents;
}

// ________________________________________________________
int String::length() const {
  return _length;
}
