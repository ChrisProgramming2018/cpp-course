// Copyright 2018
// Computer Science
// Author: Christian Leininger christianleininger@gmx.de


#include "./Set.h"

// ____________________________________________________________________________
template <class T>
Set<T>::Set() {
  _size = 0;
  _elements = new T[_size];
}

// ____________________________________________________________________________
template <class T>
Set<T>::~Set() {
  delete[] _elements;
}

// ____________________________________________________________________________
template <class T>
void Set<T>::insert(T n) {
  bool doubleElement = false;
  // check if new element is already in the list
  for (int i = 0; i < _size; i++) {
    if (_elements[i] == n) doubleElement = true;
  }
  if (!doubleElement) {
    // increse size list
    _size++;
    T* new_elements = new T[_size];
    new_elements[_size -1] = n;
    for (int i = 0; i < _size - 1; i++) {
      new_elements[i] = _elements[i];
    }
    delete[] _elements;
    _elements = new_elements;
  }
}

// ____________________________________________________________________________
template <class T>
void Set<T>::remove(T n) {
  bool remove = false;
  int saveNumber = 0;
  // search for element
  for (int i = 0; i < _size; i++) {
    if (_elements[i] == n) {
      remove = true;
      saveNumber = i;
    }
  }
  if (remove) {
    _size--;
    T* new_elemnents = new T[_size];
    for (int i = 0; i < saveNumber; i++) {
      new_elemnents[i] = _elements[i];
    }
    for (int j = saveNumber; j < _size; j++) {
      new_elemnents[j] = _elements[j + 1];
    }
    delete[] _elements;
    _elements = new_elemnents;
  }
}

// ____________________________________________________________________________
template <class T>
bool Set<T>::find(T n) {
  for (int i = 0; i < _size; i++) {
    if (_elements[i] == n) return true;
  }
  return false;
}

// ____________________________________________________________________________
template <class T>
int  Set<T>::getSize() {
  return _size;
}
template class Set<int>;  // Compile class here
