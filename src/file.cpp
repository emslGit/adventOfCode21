#include "file.h"
#include <iostream>

#include <fstream>
using namespace std;

int parse_file(
    string path,
    int buf[])
{
    string line;
    ifstream file;

    file.open(path, ios::in);

    int i = 0;
    while (getline(file, line)) {
        buf[i] = stoi(line);
        i++;
    }

    file.close();
    return 0;
}
