class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int count = 0, result = -1;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] > count) {
                count = arr[i];
                result = i;
            }
        }
        return result;
    }
};