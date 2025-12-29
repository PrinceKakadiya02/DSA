/*
LeetCode 78
Subsets
    Generate all possible subsets (power set) of the given array
    using recursion (include / exclude technique).

Time Complexity: O(2^n)
Space Complexity: O(2^n)
*/

class Solution {
private:
    void solve(vector<int> nums, vector<int> output, int index,
               vector<vector<int>>& ans) {

        // base case: all elements processed
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        // case 1: exclude current element
        solve(nums, output, index + 1, ans);

        // case 2: include current element
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index + 1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;  // stores all subsets
        vector<int> output; // current subset
        int index = 0;  // starting index

        // recursive call
        solve(nums, output, index, ans);

        return ans;
    }
};
