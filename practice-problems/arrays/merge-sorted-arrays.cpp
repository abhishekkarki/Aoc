/*
* This solution approach is to start in the reverse order of the given arrays.
* Time: O(n)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int e = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[e--] = nums1[i--];
            } else {
                nums1[e--] = nums2[j--];
            }
        }
        while (j >= 0) {
            nums1[e--] = nums2[j--];
        }
    }
};