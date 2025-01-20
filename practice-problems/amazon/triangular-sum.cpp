/*
* Triangular Sum
*/
#include <iostream>
#include <vector>

using namespace std;

int triangularSum(vector<int>& nums) {
    // base condition, if only one element
    if (nums.size() == 1) {
        return nums[0];
    }

    vector<int> nextRows;
    for (int i = 0; i < nums.size() - 1; ++i) {
        int value = (nums[i] + nums[i + 1]) % 10;
        nextRows.push_back(value);
    }

    return triangularSum(nextRows);
}

int main() {
    vector<int> list = {1, 2, 3, 4, 5};
    cout << "The sum is: " << triangularSum(list) << endl;
}