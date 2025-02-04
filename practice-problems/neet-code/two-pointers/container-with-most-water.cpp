#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxArea(vector<int>& heights) {
    int n = heights.size();
    int left = 0, right = n - 1;
    int total = 0;

    while (left < right) {
        int area = min(heights[left], heights[right]) * (right - left);

        if (heights[left] <= heights[right]) {
            ++left;
        } else {
            --right;
        }
        total = max(total, area);
    }
    return total;
}


int main() {
    vector<int> height = {1, 7, 2, 5, 4, 7, 3, 6};

    cout << "The maximum area is : " << maxArea(height) << endl;
}


//Output: 36
