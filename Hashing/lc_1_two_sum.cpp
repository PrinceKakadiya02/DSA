/*
LeetCode 1
Two Sum

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;   // value -> index

        for (int i = 0; i < nums.size(); i++) {

            int need = target - nums[i];

            // if complement already exists, return indices
            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }

            // store current number and its index
            mp[nums[i]] = i;
        }

        return {};
    }
};

/*
Input:  nums = [2,7,11,15], target = 9
Output: [0,1]

Input:  nums = [3,2,4], target = 6
Output: [1,2]

Input:  nums = [3,3], target = 6
Output: [0,1]
*/