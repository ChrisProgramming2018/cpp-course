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

// ____________________________________________________________________________
bool Movie::matches(const std::string match) const {
  std::string title = _title;
  std::transform(title.begin(), title.end(), title.begin(), ::tolower);
  return title.find(match) != std::string::npos;
}

// _____________________________________________________________________________
std::string Movie::getTitle() const {
  return _title;
}

// _____________________________________________________________________________
int Movie::getYear() const {
  return _year;
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

// _____________________________________________________________________________
AnimationMovie::AnimationMovie(const std::string title, const int year,
  const std::string studio) : Movie(title, year) {
  _studio = studio;
}

// _____________________________________________________________________________
std::string AnimationMovie::toString() const {
  std::ostringstream oss;
  oss << Movie::toString() << ", produced by " << _studio;
  return oss.str();
}

// _____________________________________________________________________________
ActionMovie::ActionMovie(const std::string title, const int year,
    const std::string director, const std::string rating)
  : Movie(title, year) {
  _director = director;
  _rating = rating;
}
