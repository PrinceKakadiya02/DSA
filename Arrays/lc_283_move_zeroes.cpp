/*
LeetCode 283
Move Zeroes

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;  // index to place next non-zero element

        // iterate through the array
        for (int j = 0; j < nums.size(); j++) {

            // if current element is non-zero
            if (nums[j] != 0) {
                swap(nums[j], nums[i]); // move non-zero to correct position
                i++;
            }
        }
    }
};
