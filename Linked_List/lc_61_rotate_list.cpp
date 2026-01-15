/*
LeetCode 61
Rotate List

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
    ListNode* rotateRight(ListNode* head, int k) {

        // Edge cases
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        // Find length and tail of the list
        int len = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }

        // Reduce unnecessary rotations
        k = k % len;
        if (k == 0) return head;

        // Use two pointers
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast k steps ahead
        while (k--) {
            fast = fast->next;
        }

        // Move both until fast reaches last node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Perform rotation
        fast->next = head;      // make list circular
        head = slow->next;      // new head
        slow->next = nullptr;   // break the circle

        return head;
    }
};

/*
Input:
head = [1,2,3,4,5], k = 2
Output:
[4,5,1,2,3]

Input:
head = [0,1,2], k = 4
Output:
[2,0,1]

Input:
head = [1], k = 1
Output:
[1]
*/
