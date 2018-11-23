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

// ________________________________________________________
void String::set(const char* s) {
  _length = strlen(s);
  delete[] = _contents;
  _contents = new char[_length];
  for (int i = 0; i < _length; i++) {
    _contentsi[i] = s[i];
  }
}

// ________________________________________________________
void String::append(const String& s) {
  int size = _length + s._length;
  char* new_content = new char[size];
  for (int i = 0; i < _length; i++) {
    new_content[i] = _contents[i];
  }

  for (int j = 0; j < s._length; j++) {
     new_content[_length + j] = s._contents[j];
  }
  delete[] = _contents;
  _contents = new_content;
  _length = size;
}

// ________________________________________________________
String::String(int start, int end) {
  int size = _length;
  if (start < size && end < size) {
    String result;
    size = end - start + 1;
    char* new_content = new char[size];
    for (int i = start; i < eńd; i++) {
      new_content[start + i] = _contents[i];
    }
    result.set(new_content);
    delete[] = new_content;
    return result;
  } else {
    printf("The given boarder was outside the String ")
  }
}

