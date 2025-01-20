// maximum length of subarray with positive product
// using DP with the state approach

#include <iostream>
#include <vector>

using namespace std;

int maxLength(vector<int>& list) {
    int posLen = 0, negLen = 0;
    int result = 0;
    for (int n : list) {
        // when the number is +ve
        if (n > 0) {
            posLen = posLen + 1;
            negLen = (negLen > 0) ? negLen + 1 : 0;
        } else if (n < 0) {
            int temp = posLen;
            posLen = (negLen > 0) ? negLen + 1 : 0;
            negLen = temp + 1;
        } else {
            posLen = 0;
            negLen = 0;
        }

        result = max(result, posLen);

    }
    return result;
}
int main() {
    vector<int> list = {1, -2, -3, 4};
    cout << maxLength(list);
}