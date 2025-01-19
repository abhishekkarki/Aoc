//number of ways to select a building (prefix count approach)
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numberOfWays(string& s) {
    int n = s.length();

    // Precompute left and right counts for 0s and 1s
    vector<int> left0(n, 0), left1(n, 0);
    vector<int> right0(n, 0), right1(n, 0);

    // Fill left counts
    for (int i = 1; i < n; ++i) {
        left0[i] = left0[i - 1] + (s[i - 1] == '0');
        left1[i] = left1[i - 1] + (s[i - 1] == '1');
    }

    // Fill right counts
    for (int i = n - 2; i >= 0; --i) {
        right0[i] = right0[i + 1] + (s[i + 1] == '0');
        right1[i] = right1[i + 1] + (s[i + 1] == '1');
    }

    long long result = 0;

    // Iterate over the string and calculate subsequences
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            // Calculate "010" subsequences
            result += (long long)left0[i] * right0[i];
        } else if (s[i] == '0') {
            // Calculate "101" subsequences
            result += (long long)left1[i] * right1[i];
        }
    }

    return result;


}

// another solution
class Solution {
public:
    long long numberOfWays(string s) {
        long long count0 = 0, count1 = 0; // Counts of 0s and 1s seen so far
        long long count01 = 0, count10 = 0; // Counts of "01" and "10" subsequences
        long long result = 0; // Total valid subsequences
        for (char c : s) {
            if (c == '0') {
                // Current '0' can complete "101" subsequences
                result += count10;
                // Update "01" subsequences count
                count01 += count1;
                // Increment count of 0s
                count0++;
            } else { // c == '1'
                // Current '1' can complete "010" subsequences
                result += count01;
                // Update "10" subsequences count
                count10 += count0;
                // Increment count of 1s
                count1++;
            }
    
        }
        return result;
    }
};

int main() {
    string s = "001101";
    std::cout << numberOfWays(s);
}