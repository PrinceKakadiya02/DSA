/*
LeetCode 141
Linked List Cycle

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        // Floyd's Cycle Detection (Tortoise & Hare)
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

/*
Input: head = [3,2,0,-4], pos = 1
Output: true

Input: head = [1,2], pos = 0
Output: true

Input: head = [1]
Output: false
*/
