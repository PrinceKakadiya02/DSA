/*
LeetCode 237
Delete Node in a Linked List

Time Complexity: O(1)
Space Complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
public:
    void deleteNode(ListNode* node) {

        // copy next node's value into current node
        node->val = node->next->val;

        // bypass the next node
        node->next = node->next->next;
    }
};

/*
Given Linked List:
4 -> 5 -> 1 -> 9
Node to delete = 5

After deletion:
4 -> 1 -> 9

Explanation:
Node 5 takes value of node 1, then skips node 1.
*/
