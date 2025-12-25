/*
LeetCode 54
Spiral Matrix

Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;      // stores spiral order result

        int n = matrix.size();  // number of rows
        int m = matrix[0].size();   // number of columns

        // boundary pointers
        int startCol = 0;
        int startRow = 0;
        int endRow = n - 1;
        int endCol = m - 1;

        int total = n * m;  // total elements to visit
        int count = 0;  // elements already added

        // continue until all elements are visited
        while (count < total) {

            // traverse top row (left to right)
            for (int index = startCol; index <= endCol && count < total; index++) {
                res.push_back(matrix[startRow][index]);
                count++;
            }
            startRow++;   // move top boundary down

            // traverse right column (top to bottom)
            for (int index = startRow; index <= endRow && count < total; index++) {
                res.push_back(matrix[index][endCol]);
                count++;
            }
            endCol--;     // move right boundary left

            // traverse bottom row (right to left)
            for (int index = endCol; index >= startCol && count < total; index--) {
                res.push_back(matrix[endRow][index]);
                count++;
            }
            endRow--;     // move bottom boundary up

            // traverse left column (bottom to top)
            for (int index = endRow; index >= startRow && count < total; index--) {
                res.push_back(matrix[index][startCol]);
                count++;
            }
            startCol++;   // move left boundary right
        }

        return res;   // return spiral order
    }
};
