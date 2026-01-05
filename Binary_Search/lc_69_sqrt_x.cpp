/*
LeetCode 69
Sqrt(x)
    Find the integer square root of a non-negative number using binary search.

Time Complexity: O(log x)
Space Complexity: O(1)
*/

class Solution {
public:
    int mySqrt(int x) {
        // Edge case
        if (x == 0) return 0;

        int start = 0, end = x;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            long long square = 1LL * mid * mid; // prevent overflow

            if (square == x) {
                return mid;   // exact square root found
            }
            else if (square < x) {
                start = mid + 1; // search right half
            }
            else {
                end = mid - 1;   // search left half
            }
        }

        // end stores the floor value of sqrt(x)
        return end;
    }
};
