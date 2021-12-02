#include "file.h"
#include <iostream>
#include <fstream>


using namespace std;

void parse_file(
    string path,
    string buf[])
{
    string line;
    ifstream file;

    file.open(path, ios::in);

    int i = 0;
    while (getline(file, line)) {
        buf[i] = line;
        i++;
    }

    file.close();
}