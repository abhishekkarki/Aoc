/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            ListNode* tempNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = tempNode; 
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head -> next) {
            return true; // list with 0 or 1 node is always palindrome
        }
        // find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        // reverse the second half of the list
        ListNode* secondHalf = reverseList(slow);

        // compare the first half with the reversed half
        ListNode* firstHalf = head;
        ListNode* secondHalfCopy = secondHalf;
        while (secondHalf != nullptr) {
            if (firstHalf -> val != secondHalf -> val) {
                reverseList(secondHalfCopy);
                return false;
            }
            firstHalf = firstHalf -> next;
            secondHalf = secondHalf -> next;
        }
        reverseList(secondHalfCopy);
        return true; //this is palindrome
    }
};