/*
LeetCode 2149
Rearrange Array Elements by Sign

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int positive = 0;   // even index for positive numbers
        int negative = 1;   // odd index for negative numbers

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {    // computer checks negative faster
                ans[negative] = nums[i];
                negative += 2;
            } else {
                ans[positive] = nums[i];
                positive += 2;
            }
        }

        return ans;
    }
};

/*
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]

Input: nums = [-1,1]
Output: [1,-1]

Input: nums = [1,-1,2,-2,3,-3]
Output: [1,-1,2,-2,3,-3]
*/

