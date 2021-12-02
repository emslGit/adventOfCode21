#!/bin/bash

echo src/day_$1.cpp
rm *.o
rm out
g++ -c src/file.cpp -std=c++20
g++ -c src/day_$1.cpp -std=c++20
g++ file.o day_$1.o -o out
./out
