// Copyright 2018
// Computer Science
// Author: Christian Leininger

#include <stdio.h>
#include <stdlib.h>
#include "./WhitMonday.cpp"

int main(int argc, char** argv) {
  // Prints if you dont give a Year
  if (argc != 2) {
    printf("Usage ./Whitmonday < Year>\n");
    exit(1);
  }
  int year = atoi(argv[1]);
  int easter = calculate(year);
  if (easter > 92) {  // from 1.3. to 1.06 are 92
    int dayInJuni = easter - 92;
    printf(" %d.Juni.%d\n", dayInJuni, year);
  } else {
    int dayInMay = easter - 61;   // from 1.3 to 1.06 are 61
    printf(" %d.Mai.%d\n", dayInMay, year);
  }
}

