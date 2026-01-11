/*
LeetCode 39
Combination Sum

Time Complexity: O(2^n)
Space Complexity: O(target)  // recursion depth
*/

class Solution {
private:
    void solve(const vector<int>& candidates, int target,
               vector<vector<int>>& res,
               vector<int>& ans,
               int index,
               int currentSum) {

        // valid combination found
        if (currentSum == target) {
            res.push_back(ans);
            return;
        }

        // out of bounds or sum exceeded
        if (index == candidates.size() || currentSum > target)
            return;

        // skip current element
        solve(candidates, target, res, ans, index + 1, currentSum);

        // pick current element (can be reused)
        ans.push_back(candidates[index]);
        solve(candidates, target, res, ans, index, currentSum + candidates[index]);
        ans.pop_back(); // backtrack
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;

        solve(candidates, target, res, ans, 0, 0);
        return res;
    }
};
/*
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Input: candidates = [2], target = 1
Output: []

Input: candidates = [1], target = 1
Output: [[1]]
*/
