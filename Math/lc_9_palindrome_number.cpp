/*
LeetCode 9
Palindrome Number

Time Complexity: O(log₁₀ n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(int x) {
        // negative numbers are not palindrome
        if (x < 0) return false;

        long rev = 0;
        int num = x;  // copy the original number

        // reverse the number
        while (num != 0) {
            rev = rev * 10 + num % 10; // add the last digit 
            num /= 10;   // remove the last digit
        }

        // check if original equals reversed
        return x == rev;
    }
};
