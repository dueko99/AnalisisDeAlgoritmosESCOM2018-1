#!/bin/sh
echo "Comiling.."
  g++ -o Program1.o Program1.cpp
  echo "Executing Test case A"
    ./Program1.o <TestCase1A.txt
  echo  "Expected output 7 "

  echo "Executing Test case B"
    ./Program1.o <TestCaseB.txt
  echo  "Expected output 15"
