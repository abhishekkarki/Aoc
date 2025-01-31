class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        // for prefix
        for (int i = 1; i < n; ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        // for postfix
        int post = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= post;
            post *= nums[i];
        }

        return res;
    }
};
