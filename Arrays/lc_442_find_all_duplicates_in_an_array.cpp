/*
LeetCode 442
Find All Duplicates in an Array
    - Elements appear at most twice

Time Complexity: O(n)
Space Complexity: O(1)   excluding output array
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;  // vector for storing the ans

        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;  // using absolute if element at position is negative

            if (nums[index] < 0) {  // if position at that index is negative than duplicate found
                ans.push_back(index + 1);  // add the duplicate item in the ans vector
            } else {
                nums[index] *= -1;  // make the element negative when visited first
            }
        }

        return ans;
    }
};
