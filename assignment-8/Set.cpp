//
//
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
  delete[] _elements:
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
    new_elements[i] =_elements[i]  
  }
  delete[] elements;
  elements = new_elements;
  }
}

