/*
Matrix Wave Print

Time Complexity: O(n * m)
Space Complexity: O(n * m)   // for result storage
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>>& matrix) {
    vector<int> res;

    int n = matrix.size();  // number of rows
    int m = matrix[0].size();   // number of columns

    // traverse column by column
    for (int col = 0; col < m; col++) {

        // even column: top to bottom
        if (col % 2 == 0) {
            for (int row = 0; row < n; row++) {
                res.push_back(matrix[row][col]);
            }
        }
        // odd column: bottom to top
        else {
            for (int row = n - 1; row >= 0; row--) {
                res.push_back(matrix[row][col]);
            }
        }
    }

    return res;   // return wave order
}
