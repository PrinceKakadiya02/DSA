/*
LeetCode 125
Valid Palindrome

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        // check characters using two pointers
        while (start < end) {

            // skip non-alphanumeric characters and also check if start go out of bound
            while (start < end && !isalnum(s[start])) start++;
            while (start < end && !isalnum(s[end])) end--;

            // compare characters ignoring case
            if (tolower(s[start]) != tolower(s[end]))
                return false;

            start++;
            end--;
        }

        return true;
    }
};
