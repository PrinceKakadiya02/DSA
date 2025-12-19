/*
LeetCode 191
Number of 1 Bits

Time Complexity: O(32)   // for 32-bit integer
Space Complexity: O(1)
*/
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while (n != 0) {
            if (n & 1) {   // check last bit
                count++;
            }
            n = n >> 1;    // right shift
        }
        return count;
    }
};
