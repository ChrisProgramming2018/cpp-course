//
//
//


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
  _contents = new char [_length];
}
