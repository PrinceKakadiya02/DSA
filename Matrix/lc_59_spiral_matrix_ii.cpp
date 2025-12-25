/*
LeetCode 59
Spiral Matrix II
    Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Time Complexity: O(n * n)
Space Complexity: O(n * n)
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // result matrix initialized with size n x n
        vector<vector<int>> res(n, vector<int>(n));

        // boundary pointers
        int startCol = 0;
        int startRow = 0;
        int endRow = n - 1;
        int endCol = n - 1;

        int total = n * n;  // total numbers to fill
        int count = 1;  // current number to insert

        // continue until matrix is completely filled
        while (count <= total) {

            // fill top row (left to right)
            for (int index = startCol; index <= endCol && count <= total; index++) {
                res[startRow][index] = count;
                count++;
            }
            startRow++;   // move top boundary down

            // fill right column (top to bottom)
            for (int index = startRow; index <= endRow && count <= total; index++) {
                res[index][endCol] = count;
                count++;
            }
            endCol--;     // move right boundary left

            // fill bottom row (right to left)
            for (int index = endCol; index >= startCol && count <= total; index--) {
                res[endRow][index] = count;
                count++;
            }
            endRow--;     // move bottom boundary up

            // fill left column (bottom to top)
            for (int index = endRow; index >= startRow && count <= total; index--) {
                res[index][startCol] = count;
                count++;
            }
            startCol++;   // move left boundary right
        }

        return res;   // return generated spiral matrix
    }
};
