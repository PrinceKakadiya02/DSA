/*
LeetCode 206
Reverse Linked List

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;   // previous node
        ListNode* curr = head;  // current node

        while (curr) {
            ListNode* nextNode = curr->next;    // store next
            curr->next = prev;  // reverse link
            prev = curr;    // move prev
            curr = nextNode;    // move curr
        }

        return prev; // new head
    }
};

/*
Input: 1 -> 2 -> 3 -> 4 -> 5
Output: 5 -> 4 -> 3 -> 2 -> 1

Input: head = []
Output: []

Input: head = [1]
Output: [1]
*/

