/*
* implementation using Floyd’s Tortoise and Hare (Cycle Detection) method, which is both 
* efficient (O(n) time complexity and O(1) space complexity):
* Here it's basically a linked list probelm and this linked list contains a cycle and the starting point of the cycle is the answer.
* i.e. detecting the starting point of the cycle in a linked list (Floyd and Hare)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // step 1: detect the cycle
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // step 2: find the entry point of the cycle (i.e. the duplicate number)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }   
        return slow;
    }
};
