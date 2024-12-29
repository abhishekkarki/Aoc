class Solution {
public:
    long unsigned int lengthOfLongestSubstring(string s) {
        int n = s.length();
        long unsigned int maxCount = 0;
        long unsigned int left = 0, right = 0;
        unordered_set<char> seen;

        while (right < n) {
            if (seen.find(s[right]) == seen.end()) { // not seen, add to the set
                seen.insert(s[right]);
                maxCount = max(maxCount, right - left + 1);
                right++;
            } else {
                seen.erase(s[left]);
                left++;
            }
        }
        return maxCount;
    }
};