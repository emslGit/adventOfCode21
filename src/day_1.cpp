#include <iostream>
#include <fstream>
#include "file.h"
using namespace std;

string buf[0xFFF];
int nums[0xFFF];
int prev_sum = 0;
int sum = 0;
int counter = 0;

int main()
{
    int j = 0;

    parse_file("inputs/in1", buf);

    for (string num : buf) {
        nums[j] = atoi(num.c_str());
        if (nums[j] == 0) {
            break;
        }
        if (j > 2) {
            prev_sum = nums[j - 1] + nums[j - 2] + nums[j - 3];
            sum = nums[j] + nums[j - 1] + nums[j - 2];
            counter = sum > prev_sum ? counter + 1 : counter;
        }
        j++;
    }

    cout << "Counter: " << counter << "\n";
    return 0;
}
