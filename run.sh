#!/bin/bash

echo src/day_$1.cpp;

if [[ -f "out" ]]; then
    rm out
    rm *.o
fi

g++ -c src/file.cpp -std=c++20
g++ -c src/day_$1.cpp -std=c++20
g++ file.o day_$1.o -o out
./out
