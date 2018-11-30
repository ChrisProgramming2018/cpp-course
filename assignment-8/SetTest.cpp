// Copyright 2018
// Computer Science
// Author: Christian Leininger christianleininger@gmx.de


#include <gtest/gtest.h>
#include "./Set.h"

// ____________________________________________________________________________
TEST(SetTest, constructorT) {
  Set<int> set;
  ASSERT_EQ(0, set._size);
}

// ____________________________________________________________________________
