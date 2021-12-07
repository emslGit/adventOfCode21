#pragma once
#include <string>
#include <vector>

void parse_file(std::string path, std::vector<std::string> buf);

// void parse_file(std::string path, std::string buf[]);

void split(std::string str, std::vector<int> *buf, char del);
