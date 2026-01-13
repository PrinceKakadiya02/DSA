/*
LeetCode 83
Remove Duplicates from Sorted List

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;   // Empty list check

        ListNode* temp = head;

        // Traverse the linked list
        while (temp->next) {
            // If current value equals next value, skip next node
            if (temp->val == temp->next->val) {
                temp->next = temp->next->next;
            } 
            // Move forward only when no duplicate
            else {
                temp = temp->next;
            }
        }
        return head;
    }
};

/*
Input:
head = [1,1,2]
Output:
[1,2]

Input:
head = [1,1,2,3,3]
Output:
[1,2,3]

Input:
head = []
Output:
[]
*/
