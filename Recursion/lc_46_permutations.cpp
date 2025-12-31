/*
LeetCode 46
Permutations
    Generates all possible permutations of the given array using backtracking
    by fixing one position at a time.

Time Complexity: O(n! * n)
Space Complexity: O(n)   // recursion stack
*/

class Solution {
private:
    void solve(vector<int> nums, vector<vector<int>>& ans, int index) {
        // Base case: one permutation completed
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Try all possible elements at current index
        for (int j = index; j < nums.size(); j++) {
            swap(nums[index], nums[j]);     // swap element at the index position one by one
            solve(nums, ans, index + 1);    // recurse
            swap(nums[index], nums[j]);     // backtrack
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;    // stores all permutations
        solve(nums, ans, 0);
        return ans;
    }
};
