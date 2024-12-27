/*
* finding next permutation i.e. the next largest number of the given number
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end()); solution using the STL
        
        // step 1: find pivot
        int n = nums.size();
        int pivot = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // step 2: next larger element
        for (int j = n - 1; j > pivot; j--) {
            if (nums[j] > nums[pivot]) {
                swap(nums[j], nums[pivot]);
                break;
            }
        }

        // step 3: reverse
        int i = pivot + 1;
        int j = n - 1;
        while (i <= j) {
            swap(nums[i++], nums[j--]);
        }
    }
};