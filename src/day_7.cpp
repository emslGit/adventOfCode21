#include "file.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>


int main () {
    std::string line;
    std::ifstream file;
    std::vector<int> positions;
    float mean = 0;
    long median = 0;
    int sum = 0;
    int fuel = 0;

    file.open("inputs/in7", std::ios::in);
    getline(file, line);
    file.close();

    std::cout << line;

    split(line, &positions, ',');
    sort(positions.begin(), positions.end(), [](int a, int b){return a > b;});
    
    median = std::round((float) positions[std::round((float) positions.size() / 2)]);
    for (int pos : positions) {
        sum += pos;
        fuel += std::abs(pos - median);
        std::cout << "Move from " << pos << " to " << median << ": " << std::abs(pos - median) << " fuel\n";
    }
    mean = std::round((float) sum / positions.size());

    std::cout << "MEAN " << mean << " MEDIAN " << median << " FUEL " << fuel << "\n";
}