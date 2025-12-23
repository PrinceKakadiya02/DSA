/*
LeetCode 1752
Check if Array Is Sorted and Rotated

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        // count number of order breaks
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i])
                count++;
        }

        // check rotation break between last and first
        if (nums[n - 1] > nums[0])
            count++;

        // array is sorted and rotated if breaks <= 1
        return count <= 1;
    }
};
