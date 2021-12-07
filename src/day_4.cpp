#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>


typedef struct board {
    std::vector<int> nums;
    std::vector<bool> marked;
} board_t;

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
}


int main()
{
    std::vector<int> vec =
    { 7, 4, 9, 5, 11, 17, 23, 2, 0, 14, 21, 24, 10, 16, 13, 6, 15, 25, 12, 22, 18, 20, 8, 19, 3, 26, 1 };
    std::vector<board_t> boards;
    board_t board;
    std::ifstream file;
    std::string line;
    std::string line_concat;

    file.open("inputs/in4", std::ios::in);
    while (1) {
        line_concat += (line + " ");
        if (line == "" || !getline(file, line)) {
            line_concat.erase(unique(line_concat.begin(), line_concat.end(), [ = ](char lhs, char rhs){
                return (lhs == rhs) && (lhs == ' ');
            }), line_concat.end());

            if (*line_concat.begin() == ' ') {
                line_concat = line_concat.substr(1, line_concat.size());
            }
            if (*(line_concat.end() - 1) == ' ') {
                line_concat = line_concat.substr(0, line_concat.size() - 1);
            }

            board = {};
            split(line_concat, &board.nums, ' ');
            boards.push_back(board);
            line_concat = "";

            if (!getline(file, line)) {
                break;
            }
        }
    }
    file.close();

    for (int num : vec) {
        for (board_t b: boards) {
            int idx = std::find(vec.begin(), vec.end(), num) != vec.end();
            if (idx >= 0) {
                b.marked[idx] = 1;
            }
        }
    }

    return 0;
} // main
