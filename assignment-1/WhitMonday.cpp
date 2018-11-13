// Copyright 2018
// Computer Science
// Author: Christian Leininger

#include <stdio.h>

// Using the Algoritm from Gauß that Calculate the Eastersunday
// for the greoriansichen Calendar
// Function to calculate
int calculate(int year) {
  int a = year % 19;
  int b = year %  4;
  int c = year %  7;
  int k = year / 100;
  int p = (8*k + 13) / 25;
  int q = k / 4;
  int M = (15 + k - p - q) % 30;
  int d = ((19 * a) + M) % 30;
  int N = (4 + k - q) % 7;
  int e = (2 * b + 4 * c + 6 * d + N) % 7;
  int days = (22 + d + e);
  days += 50;  // because 50 days later are Whitmonday
  return days;  // the days from 01.03 to Whitmonday
}

