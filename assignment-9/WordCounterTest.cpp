// Copyright 2018
// Computer Science
// Author: Christian Leininger christianleininger@gmx.de

#include <gtest/gtest.h>
#include <string>
#include <utility>
#include <vector>
#include "./WordCounter.h"


// ____________________________________________________________________________
TEST(WordCounterTest, readFile) {
  FILE* input = fopen("WordCounterTest.tmp", "w");
  fprintf(input,"test test more\n nextline\n end\n");
  fclose(input);

  WordCounter wc;

  wc.readFile(std::string("WordCounterTest.tmp"));
  //ASSERT_EQ(4, wc._words);
}
