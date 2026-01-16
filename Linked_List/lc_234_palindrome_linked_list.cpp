/*
LeetCode 234
Palindrome Linked List

Time Complexity: O(n)
Space Complexity: O(n)   // stack used
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
    bool isPalindrome(ListNode* head) {

        stack<int> st;
        ListNode* slow = head;
        ListNode* fast = head;

        // push first half values into stack
        while (fast != nullptr && fast->next != nullptr) {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        // skip middle node for odd length list
        if (fast != nullptr) {
            slow = slow->next;
        }

        // compare second half with stack
        while (slow != nullptr) {
            if (st.top() != slow->val) {
                return false;
            }
            st.pop();
            slow = slow->next;
        }

        return true;
    }
};

/*
Input:  1 -> 2 -> 2 -> 1
Output: true

Input:  1 -> 2
Output: false

Input:  1
Output: true
*/
