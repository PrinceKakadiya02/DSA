/*
LeetCode 19
Remove Nth Node From End of List

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast pointer n steps ahead
        while (n--) {
            fast = fast->next;
        }

        // If fast becomes null, remove the head node
        if (fast == nullptr) {
            return head->next;
        }

        // Move both pointers until fast reaches last node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the nth node from end
        slow->next = slow->next->next;

        return head;
    }
};

/*
Input:
head = [1,2,3,4,5], n = 2
Output:
[1,2,3,5]

Input:
head = [1], n = 1
Output:
[]

Input:
head = [1,2], n = 1
Output:
[1]
*/
