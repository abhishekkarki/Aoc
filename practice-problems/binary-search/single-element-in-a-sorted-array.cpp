class Solution {
private:
    int helper(vector<int>& list, int start, int end) {
        while (start < end) {
            int mid = start + (end - start) / 2;

            // mid should be the first element of the pair
            if ((mid % 2) == 1) {
                mid--;
            }

            if (list[mid] == list[mid + 1]) {
                start = mid + 2;
            } else {
                end = mid;
            }
        }
        return list[start];
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};