
/*
* Container with most water solution using 2 pointer approach
* Time: O(n), Space: O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int leftPtr = 0;
        int rightPtr = height.size() - 1;

        while (leftPtr < rightPtr) {
            int width = rightPtr - leftPtr;
            int length = min(height[leftPtr], height[rightPtr]);
            int area = width * length;
            result = max(result, area);
            height[leftPtr] < height[rightPtr] ? leftPtr++ : rightPtr--;

        }
        return result;
    }
};