#include "file.h"
#include <cstring>
#include <iostream>
using namespace std;

typedef struct pos {
    int x;
    int y;
    int aim;
} pos_t;

string buf[0xFFF];
pos_t current_pos = { 0, 0 };

void _move(
    int i)
{
    string str = buf[i];

    if (str != "\0") {
        int j = str.find(" ");
        string dir = str.substr(0, j);
        int magn = atoi(str.substr(j + 1).c_str());

        if (dir == "forward") {
            current_pos.x += magn;
            current_pos.y += magn * current_pos.aim;
        } else if (dir == "up") {
            current_pos.aim -= magn;
        } else if (dir == "down") {
            current_pos.aim += magn;
        }

        cout << current_pos.x << " " << current_pos.y << " " << current_pos.aim << "\n";

        _move(i + 1);
    }
}


int main()
{
    parse_file("inputs/in2", buf);

    _move(0);
    cout << "Position " << current_pos.x << ", " << current_pos.y << "\n";
    cout << "Product " << current_pos.x * current_pos.y << "\n";
    return 0;
}
