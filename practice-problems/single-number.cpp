/*
* every number has a duplicate in the vector except one and we need to return that unique one
* using XOR we can find the unique number
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (auto val : nums) {
            ans ^= val;
        }
        return ans;
    }
};