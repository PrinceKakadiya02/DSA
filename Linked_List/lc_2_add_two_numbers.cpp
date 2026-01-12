/*
LeetCode 2
Add Two Numbers

Time Complexity: O(max(n, m))
Space Complexity: O(max(n, m))   // Result list
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);          // Dummy head for result list
        ListNode* temp = &dummy;
        int carry = 0;

        // Continue until both lists and carry are exhausted
        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) +
                      (l2 ? l2->val : 0) +
                      carry;

            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy.next;
    }
};


/*
Input:
l1 = [2,4,3]
l2 = [5,6,4]
Output:
[7,0,8]

Input:
l1 = [0]
l2 = [0]
Output:
[0]

Input:
l1 = [9,9,9,9,9,9,9]
l2 = [9,9,9,9]
Output:
[8,9,9,9,0,0,0,1]
*/
