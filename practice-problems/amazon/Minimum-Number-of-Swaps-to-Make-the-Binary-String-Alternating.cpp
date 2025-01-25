#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

int minSwaps(string s) {
    if (s.empty()) return -1;

    int n = s.size();

    string alt1 = "", alt2 = "";
    for (int i = 0; i < n; ++i) {
        alt1 += (i % 2 == 0) ? '0' : '1'; // 010101....
        alt2 += (i % 2 == 1) ? '1' : '0'; // 101010.... 
    }

    // counting mismatches with each pattern
    int mismatchAlt1 = 0, mismatchAlt2 = 0;
    int count0 = 0, count1 = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') count0++;
        else count1++;

        if (s[i] != alt1[i]) mismatchAlt1++; // miss match with 01010...
        if (s[i] != alt1[i]) mismatchAlt2++; // miss match with 10101...
    }

    // check if it is impossible to make the string alternating
    if (abs(count0 - count1) > 1) return -1;

    // calculate the number of swaps needed
    int swaps = INT_MAX;
    if (count0 == count1 || count0 > count1) {
        swaps = min(swaps, mismatchAlt1 / 2); // swap for 01010...
    }
    if (count0 == count1 || count1 > count0) {
        swaps = min(swaps, mismatchAlt2 / 2); // swap for "101010..."
    }
    return swaps;
}

int main() {
    string s = "010";
    cout << minSwaps(s) << endl;
}