// Copyright 2018
// Computer Sicence
// Autor: Christian Leininger christianleininger@gmx.de

#ifndef
#define

#include <gtest/gtest.h>
#include <string>
class Movie {
 public:
  Movie(const std::string title, const int year);
  
  // frees the memory
  virtual ~ Movie() {} 
 private:

};

#endif  // 
