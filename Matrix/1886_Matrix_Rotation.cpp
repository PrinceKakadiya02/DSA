/*
LeetCode 1886
Determine Whether Matrix Can Be Obtained By Rotation
    Check if the given matrix can be rotated in 90-degree steps
    to match the target matrix.

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

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int i = 4; // for all possible combinations 0, 90, 180, 270
        while (i > 0) {
            if (mat == target) {    // check if both matrices are same
                return true;
            }
            rotate(mat); // if not match rotate the matrix
            i--;
        }
        return false;
    }
};
