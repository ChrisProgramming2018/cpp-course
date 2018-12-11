// Copyright 2018
// Computer Science
// Autor: Christian Leininger christianleininger@gmx.de


#include <algorithm>
#include <sstream>
#include <string>
#include "./Movie.h"


// ____________________________________________________________________________
Movie::Movie(const std::string title, const int year) {
  _title = title;
  _year = year;
}


// _____________________________________________________________________________
std::string Movie::toString() const {
  std::ostringstream oss;
  oss << "\"" << _title << "\"" << " " << "(" << _year << ")";
  return oss.str();
}
// _____________________________________________________________________________
std::string ActionMovie::toString() const {
  std::ostringstream oss;
  oss << Movie::toString() << ", directed by " << _director << ", rated: "
    << _rating;
  return oss.str();
}
