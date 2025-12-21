/*
LeetCode 724
Find Pivot Index

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        // Build prefix sum in-place
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }

        // Check pivot at index 0
        if (nums[n - 1] - nums[0] == 0)
            return 0;

        // Check pivots from index 1 to end
        for (int i = 1; i < n; i++) {
            // left sum = right sum
            if (nums[i - 1] == nums[n - 1] - nums[i])
                return i;
        }

        // no pivot index found
        return -1;
    }
};
