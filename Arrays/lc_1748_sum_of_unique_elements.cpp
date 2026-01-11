/*
LeetCode 1748
Sum of Unique Elements

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        int sum = 0;

        // count frequency of each element
        for (int num : nums) {
            freq[num]++;
        }

        // add elements that appear exactly once
        for (int num : nums) {
            if (freq[num] == 1) {
                sum += num;
            }
        }

        return sum;
    }
};


/*
Input: nums = [1,2,3,2]
Output: 4
Explanation: Unique elements are 1 and 3 → 1 + 3 = 4

Input: nums = [1,1,1,1,1]
Output: 0

Input: nums = [1,2,3,4,5]
Output: 15
*/
