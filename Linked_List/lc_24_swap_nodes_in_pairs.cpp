/*
LeetCode 24
Swap Nodes in Pairs

Approach: Recursion (Linked List)

Time Complexity: O(n)
Space Complexity: O(n)  // recursion stack
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
    ListNode* swapPairs(ListNode* head) {

        // base case: empty list or single node
        if (head == nullptr || head->next == nullptr)
            return head;

        // second node becomes new head of this pair
        ListNode* second = head->next;
        ListNode* newHead = second;

        // swap the pair
        head->next = second->next;
        second->next = head;

        // recursively swap remaining list
        head->next = swapPairs(head->next);

        return newHead;
    }
};

/*
Input:  head = [1,2,3,4]
Output: [2,1,4,3]

Input:  head = [1]
Output: [1]

Input:  head = []
Output: []

Input:  head = [1,2,3]
Output: [2,1,3]
*/
