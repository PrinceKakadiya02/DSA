/*
LeetCode 118
Pascal's Triangle

Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> res(numRows);

        // build each row
        for (int row = 0; row < numRows; row++) {

            res[row].resize(row + 1);

            for (int col = 0; col <= row; col++) {

                // first and last elements are always 1
                if (col == 0 || col == row)
                    res[row][col] = 1;
                else
                    res[row][col] = res[row - 1][col - 1] + res[row - 1][col];
            }
        }

        return res;
    }
};

/*
Input:  numRows = 1
Output: [[1]]

Input:  numRows = 5
Output:
[
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
]

Input:  numRows = 0
Output: []
*/
