/*
LeetCode 231
Power of Two

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        // if n = 64, n-1 = 63
        // 100000 & 011111 = 000000
        return (n & (n - 1)) == 0;
    }
};
