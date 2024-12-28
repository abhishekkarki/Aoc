/*
* Merge interval 
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // step 1: sort the first element of the intervals pairs
        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b){
                return a[0] < b[0];
            });

        // step 2: merge on fly
        vector<vector<int>> merge;
        for (const auto& interval : intervals) {
            // if the merge is empty or the interval do not overlap
            if (merge.empty() || merge.back()[1] < interval[0]) {
                merge.push_back(interval);
            } else {
                // when the interval overlaps
                merge.back()[1] = max(merge.back()[1], interval[1]);
            }
        }
        return merge;
    }
};