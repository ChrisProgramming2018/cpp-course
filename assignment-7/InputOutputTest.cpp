// Copyright 2018
// Computer Science
// Author : Christian Leininger christianleininger@gmx.de


#include <gtest/gtest.h>
#include "./InputOutput.h"

// ________________________________________________________
TEST(InputOutputTest, parseCommandLineArguments) {
  InputOutput io;
  int argc = 2;
  char* argv[2] = {
    const_cast<char*>("./ReverterMain"),
    const_cast<char*>("t.txt")
  };
  io.parseCommandLineArguments(argc, argv);
  ASSERT_STREQ("t.txt", io._filename);
  ASSERT_FALSE(io._palindromes);
}

// ________________________________________________________
TEST(InputOutputTest, parseCommandLineArguments2) {
  InputOutput io;
  int argc = 1;
  char* argv[1] = {
    const_cast<char*>("./InputOutputMain ") };
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  ASSERT_DEATH(io.parseCommandLineArguments(argc, argv), "Usage:.*");
}
// ________________________________________________________
TEST(InputOutputTest, process) {
  InputOutput io;
  int argc = 5;
  char* argv[5] = {
    const_cast<char*>("./ReverterMain"),
    const_cast<char*>("-p"),
    const_cast<char*>("test.txt"),
    const_cast<char*>(" > "),
    const_cast<char*>("outputtest.txt")
  };
  io.parseCommandLineArguments(argc, argv);
  ASSERT_STREQ("test.txt", io._filename);
  ASSERT_TRUE(io._palindromes);
  io.process();
}
