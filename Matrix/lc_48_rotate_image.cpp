/*
LeetCode 48
Rotate Image
    Rotate the given n x n matrix by 90 degrees clockwise
    in-place without using extra space.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose the matrix (swap across diagonal)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
