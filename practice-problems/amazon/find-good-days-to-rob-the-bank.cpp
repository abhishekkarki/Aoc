// Find good days to rob the bank
#include <iostream>
#include <vector>

using namespace std;

vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    // use two list one keeps the prefix and other will keep the suffix
    int n = security.size();
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);
    vector<int> result;

    for (int i = 1; i < n; ++i) {
        if (security[i] <= security[i - 1]) {
            prefix[i] = security[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        if (security[i] <= security[i + 1]) {
            suffix[i] = security[i + 1] + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (prefix[i] >= time + 1 && suffix[i] >= time + 1) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    vector<int> days = {5, 3, 3, 3, 5, 6, 2};
    int time = 2;
    vector<int> result = goodDaysToRobBank(days, time);

    for (const int& i : result) {
        cout << i << " ";
    } cout << endl;
}