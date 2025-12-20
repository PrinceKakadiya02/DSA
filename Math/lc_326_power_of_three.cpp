/*
LeetCode 326
Power of Three

Time Complexity: O(log₃ n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;  // special case

        while (n % 3 == 0) { // check if divisable by 3
            n /= 3;  // divide the n by 3
        }

        return n == 1;  // if power of 3 then n will be 1
    }
};
