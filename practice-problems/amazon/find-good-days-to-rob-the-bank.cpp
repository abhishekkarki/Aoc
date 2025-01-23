#include <iostream>
#include <vector>

using namespace std;

vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    int n = security.size();
    vector<int> prefix(n, 0);
    vector<int> suffix(n, 0);
    vector<int> result;

    // take the prefix from left to right
    for (int i = 1; i < n; ++i) {
        if (security[i] <= security[i - 1]) {
            prefix[i] = prefix[i - 1] + 1; 
        } 
    }

    // take the suffix from right to left
    for (int i = n - 2; i >= 0; --i) {
        if (security[i] <= security[i + 1]) {
            suffix[i] = suffix[i + 1] + 1;
        }
    }

    // if the prefix and suffix are more than the defined time then return them
    for (int i = 0; i < n; ++i) {
        if (prefix[i] >= time && suffix[i] >= time) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    vector<int> days = {5, 3, 3, 3, 5, 6, 2};
    int time = 2;
    vector<int> result = goodDaysToRobBank(days, time);

    cout << "Good days to rob the bank: ";
    for (const int& i : result) {
        cout << i << " ";
    }
    cout << endl;
}