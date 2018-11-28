//
//
// Author: Christian Leininger christianleininger@gmx.de


#include "./Set.h"

// ________________________________________________________
template <class T> 
Set<T>::Set() {
  _size = 0;
  _elements = new T[_size];
}


