/*
LeetCode 143
Reorder List

Time Complexity: O(n)
Space Complexity: O(n)   // stack usage
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
    void reorderList(ListNode* head) {

        // edge cases
        if (!head || !head->next) return;

        // find middle of the list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // push second half nodes into stack
        stack<ListNode*> st;
        ListNode* curr = slow->next;
        slow->next = nullptr;   // split the list

        while (curr) {
            st.push(curr);
            curr = curr->next;
        }

        // merge first half with reversed second half
        curr = head;
        while (!st.empty()) {
            ListNode* nextNode = curr->next;
            curr->next = st.top();
            st.pop();

            curr = curr->next;
            curr->next = nextNode;
            curr = nextNode;
        }
    }
};

/*
Input:  head = [1,2,3,4]
Output: [1,4,2,3]

Input:  head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Input:  head = [1]
Output: [1]

Input:  head = [1,2]
Output: [1,2]
*/
