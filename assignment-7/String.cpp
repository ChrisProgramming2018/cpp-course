// Copyright 2018
// Computer Science
// Author: Christian Leininger Christianleininger@gmx.de

#include <stdio.h>
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
    _contents[i] = s._contents[i];
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
  delete[]  _contents;
  _contents = new char[_length];
  for (int i = 0; i < _length; i++) {
    _contents[i] = s[i];
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
  delete[] _contents;
  _contents = new_content;
  _length = size;
}

// ________________________________________________________
void String::substr(const int start, const int end, String* result) const {
  if (start > _length) {
    result->set("");
    return;
  }
  if (end < start) {
    result->set("");
    return;
  }
  if (start < 0) {
    result->set("");
    return;
  }
  char* chars = new char[end - start + 1];
  for (int i = start; i < end; i++) {chars[i - start] = _contents[i]; }
  chars[end - start] = 0;
  result->set(chars);
  delete[] chars;
}

// ________________________________________________________
void String::reverse() {
  char* new_content = new char[_length];
  for (int i = 1; i <= _length; i++) {
    new_content[i -1] = _contents[_length - i];
  }
  delete[] _contents;
  _contents = new_content;
}

// ________________________________________________________
void String::reversePrint() {
  char* new_chars = new char[_length + 1];
  for (int i = 0; i < _length; i++) {
    new_chars[_length - i - 1] = _contents[i];
  }
  new_chars[_length] = 0;
  set(new_chars);
  delete[] new_chars;
  for (int i = 0; i < _length; i++) {
    printf("%c", _contents[i]);
  }
  printf("\n");
}
