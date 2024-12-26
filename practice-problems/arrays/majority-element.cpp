class Solution {
private:
    // brutforce approach
    int brutforceSol(vector<int>& nums) {
        int n = nums.size();
        for (auto val : nums) {
            int freq = 0;
            for (auto el : nums) {
                if (val == el) {
                    freq++;
                }
            }
            if (freq > (n / 2)) {
                return val;
            }
        }
        return -1;
    }

    // sorting approach
    int sortingSol(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int freq = 0; 
        int ans = nums[0];
        int n = nums.size();
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == ans) {
                freq++;
            } else {
                freq = 1;
                ans = nums[i];
            }
            if (freq > (n / 2)) {
                return ans;
            }
        }
        return -1;
    }

    // moore's approach
    int mooreSol(vector<int>& nums) {
        int ans = 0, freq = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (freq == 0) {
                ans = nums[i];
            }
            if (ans == nums[i]) {
                freq++;
            } else {
                freq--;
            }

        }
        return ans;
    }

public:
    int majorityElement(vector<int>& nums) {
        brutforceSol(nums);    // brutforce approach O(n^2)
        sortingSol(nums);      // sorting approach O(log(n))
        return mooreSol(nums); // moore approach O(n)
    }
};