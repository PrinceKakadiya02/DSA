/*
LeetCode 82
Remove Duplicates from Sorted List II

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

        // dummy node to handle deletions at head
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;  // last node before duplicates
        ListNode* curr = head;    // current node being checked

        while (curr != nullptr) {

            // detect start of duplicates
            if (curr->next != nullptr && curr->val == curr->next->val) {
                int duplicateVal = curr->val;

                // skip all nodes with duplicateVal
                while (curr != nullptr && curr->val == duplicateVal) {
                    curr = curr->next;
                }

                // link previous unique node to next unique node
                prev->next = curr;
            }
            else {
                // no duplicate, move both pointers
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};


/*
Input:  head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Input:  head = [1,1,1,2,3]
Output: [2,3]

Input:  head = [1,1]
Output: []

Input:  head = [1]
Output: [1]
*/
