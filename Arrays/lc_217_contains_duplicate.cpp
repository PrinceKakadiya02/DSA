/*
LeetCode 217
Contains Duplicate

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> seen;

        for (int num : nums) {

            // if element already exists, duplicate found
            if (seen.count(num)) {
                return true;
            }

            seen.insert(num);
        }

        return false;
    }
};

/*
LeetCode 217
Contains Duplicate

Approach: Sorting

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // sort the array so duplicates become adjacent
        sort(nums.begin(), nums.end());

        // check adjacent elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
    }
};


/*
Input: nums = [1,2,3,1]
Output: true

Input: nums = [1,2,3,4]
Output: false

Input: nums = [1]
Output: false
*/
