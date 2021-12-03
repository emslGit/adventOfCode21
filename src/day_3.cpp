#include "file.h"
#include <iostream>
#include <bitset>
#include <string>
#define LEN 12
using namespace std;

int nums[0xFFF];
int signs[LEN];

void task_1()
{
    int gamma = 0;
    int epsilon = 0;

    for (int i = 0; i < LEN; i++) {
        gamma = gamma | (signs[i] > 0) << i;
        epsilon = epsilon | (signs[i] <= 0) << i;
    }
    cout << "G " << bitset<LEN>(gamma) << " E " << bitset<LEN>(epsilon) << " Prod " << gamma * epsilon << "\n";
}


void task_2(
    int buf[],
    int i)
{
    int j = 0;
    int k = 0;
    int sign = 0;
    int new_buf[0xFFF];

    do {
        sign += (buf[j] & (1 << i)) ? +1 : -1;
    } while (buf[++j]);

    j = 0;
    do {
        if (!buf[1]) {
            cout << buf[0] << "\n";
            return;
        }

        /* add ! to switch between oxygen and co2 */
        if ((sign >= 0) ? (buf[j] & (1 << i)) : !(buf[j] & (1 << i))) {
            new_buf[k++] = buf[j];
        }
    } while (buf[++j]);

    if (i == 0) {
        cout << new_buf[0] << "\n";
        return;
    }

    task_2(new_buf, --i);
}


int main()
{
    string buf[0xFFF];
    int j = 0;

    parse_file("inputs/in3", buf);

    for (string line : buf) {
        if (line == "\0") {
            break;
        }
        nums[j] = (int) bitset<LEN>(line).to_ulong();
        for (int i = 0; i < LEN; i++) {
            signs[LEN - i - 1] += (nums[j] & (1 << (LEN - i - 1))) ? 1 : -1;
        }
        j++;
    }

    task_1();
    task_2(nums, LEN - 1);
}
