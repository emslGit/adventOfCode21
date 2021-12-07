#include "file.h"
#include <iostream>
#include <fstream>


using namespace std;

void parse_file(
    string path,
    vector<string> buf)
{
    string line;
    ifstream file;

    file.open(path, ios::in);

    while (getline(file, line)) {
        buf.push_back(line);
    }

    file.close();
}

void split(
    std::string str,
    std::vector<int> *buf,
    char del)
{
    std::string tmp = "";

    for (char c : str) {
        if (c == del) {
            buf->push_back(std::stoi(tmp.c_str()));
            tmp = "";
        } else {
            tmp += c;
        }
    }
    buf->push_back(std::stoi(tmp.c_str()));
}