/*
LeetCode 868
Binary Gap

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int binaryGap(int n) {

        int maxDistance = 0;
        int lastPos = -1;     // stores position of previous 1 bit
        int pos = 0;          // current bit position

        while (n > 0) {

            if (n & 1) {

                // if we have seen a 1 before, calculate distance
                if (lastPos != -1) {
                    maxDistance = max(maxDistance, pos - lastPos);
                }

                lastPos = pos;
            }

            n >>= 1;
            pos++;
        }

        return maxDistance;
    }
};

/*
Input:  n = 22   (10110)
Output: 2

Input:  n = 8    (1000)
Output: 0

Input:  n = 5    (101)
Output: 2
*/
