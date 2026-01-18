/*
LeetCode 448
Find All Numbers Disappeared in an Array

Time Complexity: O(n)
Space Complexity: O(1)   // excluding output array
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> res;

        // mark visited numbers by making index negative
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }

        // numbers with positive values were never visited
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};

/*
Input:  nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Input:  nums = [1,1]
Output: [2]

Input:  nums = [2,2]
Output: [1]
*/
