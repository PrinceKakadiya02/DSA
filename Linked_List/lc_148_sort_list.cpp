/*
LeetCode 148
Sort List (Merge Sort on Linked List)

Time Complexity: O(n log n)
Space Complexity: O(log n)  // recursion stack
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
    ListNode* sortList(ListNode* head) {

        // base case: empty list or single node
        if (!head || !head->next) return head;

        // find middle using slow-fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // split the list into two halves
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // merge sorted halves
        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        // merge two sorted lists
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // attach remaining nodes
        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }
};

/*
Input:  head = [4,2,1,3]
Output: [1,2,3,4]

Input:  head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Input:  head = []
Output: []

Input:  head = [1]
Output: [1]
*/
