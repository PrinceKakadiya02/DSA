/*
LeetCode 876
Middle of the Linked List

Time Complexity: O(n)
Space Complexity: O(1)
*/

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
public:
    ListNode* middleNode(ListNode* head) {

        // slow moves 1 step, fast moves 2 steps
        ListNode* slow = head;
        ListNode* fast = head;

        // when fast reaches end, slow is at middle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;  // middle node
    }
};

/*
Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 3

Input:  1 -> 2 -> 3 -> 4 -> 5 -> 6
Output: 4
(Second middle is returned)
*/
