/*
LeetCode 74
Search a 2D Matrix

Time Complexity: O(log(n * m))
Space Complexity: O(1)
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();    // total rows
        int col = matrix[0].size();    // total columns

        // binary search range on virtual 1D array
        int start = 0;
        int end = row * col - 1;

        while (start <= end) {

            // mid index of 1D array
            int mid = start + (end - start) / 2;

            // map 1D index to 2D matrix position
            int element = matrix[mid / col][mid % col];
 
            // if target found
            if (element == target) {
                return true;
            }
            // move right
            else if (element < target) {
                start = mid + 1;
            }
            // move left
            else {
                end = mid - 1;
            }
        }

        // target not found
        return false;
    }
};
