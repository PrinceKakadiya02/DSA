/*
LeetCode 240
Search a 2D Matrix II
    -Integers in each row are sorted in ascending from left to right.
    -Integers in each column are sorted in ascending from top to bottom.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();  // number of rows
        int m = matrix[0].size();   // number of columns

        // start from top-right corner
        int r = 0;
        int c = m - 1;

        // move until indices are valid
        while (r < n && c >= 0) {

            // current element is smaller → move down
            if (matrix[r][c] < target) {
                r++;
            }
            // current element is larger → move left
            else if (matrix[r][c] > target) {
                c--;
            }
            // target found
            else {
                return true;
            }
        }
        // target not found
        return false;
    }
};
