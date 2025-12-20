/*
LeetCode 1009
Complement of Base 10 Integer

Time Complexity: O(d)
Space Complexity: O(1)
*/

class Solution {
public:
    int bitwiseComplement(int n) {
        int num = n;
        int mask = 0;  // mask is of all the bits as 1

        // special case
        if (n == 0) {
            return 1;
        }

        // create mask with same number of bits as n
        while (num != 0) {
            mask = (mask << 1) | 1;
            num = num >> 1;
        }

        return (~n) & mask;  // complementing the n
    }
};
