/*
* Problem of # sum
*/

//________________________________________________________________________
// BrutForce solution
// Time: O(n^3 * log(unique triplet))
// Space: O(unique triplet)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> elements;
        std::set<std::vector<int>> s; 
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    if ((nums[i] + nums[j] + nums[k]) == 0) {
                        std::vector<int> triplet = {nums[i], nums[j], nums[k]};
                        std::sort(triplet.begin(), triplet.end());

                        if (s.find(triplet) == s.end()) {
                            s.insert(triplet);
                            elements.push_back(triplet);
                        }
                    }
                }
            }
        }
        return elements;
    }
};

//________________________________________________________________________
// Approaching with Hashing
// Time: O(n^2 * log(uniqe triplet))
// space: O(Unique triplet + n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> uniqueTriplets;
        for (int i = 0; i < nums.size(); ++i) {
            int target = -nums[i];
            set<int> s;
            for(int j = i + 1; j < nums.size(); ++j) {
                int third = target - nums[j];

                if (s.find(third) != s.end()) {
                    vector<int> triplet = {nums[i], nums[j], third};
                    sort(triplet.begin(), triplet.end());
                    uniqueTriplets.insert(triplet);
                }
                s.insert(nums[j]);
            }
        }
        vector<vector<int>> result(uniqueTriplets.begin(), uniqueTriplets.end());
        return result;
    }
};


//________________________________________________________________________
// Approaching with two pointer
// Time: O(n^2 * nlogn)
// space: O(Unique triplet)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    ans.push_back(triplet);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j- 1]) j++;
                }

            }
        }
        return ans;
    }
};


