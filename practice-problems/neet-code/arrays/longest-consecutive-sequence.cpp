#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    int length = 0;
    unordered_set<int> container(nums.begin(), nums.end()); // Insert all numbers

    for (int num : nums) {
        // Check if num is the start of a sequence
        if (container.find(num - 1) == container.end()) {  
            int currentNum = num;
            int count = 1;  // Current sequence length

            while (container.find(currentNum + 1) != container.end()) {
                currentNum++;
                count++;
            }

            length = max(length, count);
        }
    }
    
    return length;
}

int main() {
    vector<int> nums = {2, 20, 4, 10, 3, 4, 5};

    cout << "The answer is: " << longestConsecutive(nums) << endl;
    return 0;
}