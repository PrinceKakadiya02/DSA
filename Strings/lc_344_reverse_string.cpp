/*
LeetCode 344
Reverse String

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;

        // reverse using two pointers
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};
