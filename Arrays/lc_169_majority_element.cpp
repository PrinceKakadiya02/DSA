/*
LeetCode 169
Majority Element

Find the element that appears more than ⌊n / 2⌋ times using Boyer-Moore Voting Algorithm.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int i = 0; i < nums.size(); i++) {
            // pick new candidate when count becomes zero
            if (count == 0)
                candidate = nums[i];

            // increment or decrement count
            if (nums[i] == candidate)
                count++;
            else
                count--;
        }

        return candidate;
    }
};

/*
Test Cases:

Input:  nums = [3,2,3]
Output: 3

Input:  nums = [2,2,1,1,1,2,2]
Output: 2

Input:  nums = [1]
Output: 1

Input:  nums = [5,5,5,2,2]
Output: 5
*/
