/*
LeetCode 2460
Apply Operations to an Array

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    // move all zeroes to the end while maintaining order of non-zero elements
    void moveZeroes(vector<int>& nums) {
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                swap(nums[j], nums[i]);
                i++;
            }
        }
    }

    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // apply doubling operation on adjacent equal elements
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // move all zeroes to the end
        moveZeroes(nums);

        return nums;
    }
};

/*
Input: nums = [1,2,2,1,1,0]
Output: [1,4,2,0,0,0]

Input: nums = [0,1]
Output: [1,0]

Input: nums = [2,2,2,2]
Output: [4,4,0,0]

Input: nums = [1,1,1,1]
Output: [2,2,0,0]
*/
