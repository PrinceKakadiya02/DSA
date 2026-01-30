/*
LeetCode 25
Reverse Nodes in k-Group

Time Complexity: O(n)
Space Complexity: O(n / k)   // recursion stack
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
    ListNode* reverseKGroup(ListNode* head, int k) {

        // base case: empty list
        if (head == nullptr) return nullptr;

        // check if there are at least k nodes left
        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (check == nullptr) return head;  // not enough nodes
            check = check->next;
        }

        // reverse k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        int count = 0;

        while (curr != nullptr && count < k) {
            next = curr->next;  // store next node
            curr->next = prev;  // reverse link
            prev = curr;    // move prev forward
            curr = next;    // move curr forward
            count++;
        }

        // recursively reverse remaining list
        head->next = reverseKGroup(curr, k);

        // prev becomes new head of this k-group
        return prev;
    }
};

/*
Input:  head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Input:  head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Input:  head = [1,2], k = 3
Output: [1,2]

Input:  head = [], k = 1
Output: []
*/
