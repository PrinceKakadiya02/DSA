/*
LeetCode 21
Merge Two Sorted Lists

Time Complexity: O(n + m)
Space Complexity: O(1)   // Iterative, no extra list created
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);      // Dummy head node
        ListNode* tail = &dummy;

        // Merge while both lists have nodes
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes
        tail->next = list1 ? list1 : list2;

        return dummy.next;
    }
};


/*
Input:
list1 = [1,2,4]
list2 = [1,3,4]
Output:
[1,1,2,3,4,4]

Input:
list1 = []
list2 = []
Output:
[]

Input:
list1 = []
list2 = [0]
Output:
[0]
*/
