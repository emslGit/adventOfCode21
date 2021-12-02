#include <iostream>
#include <fstream>
#include "file.h"
#define PATH "input"
using namespace std;

int prev_sum = 0;
int sum = 0;
int nums[0xFFF];
int counter = 0;

int main()
{
    int j = 0;

    parse_file(PATH, nums);

    for (int num : nums) {
        if (num == 0) {
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
