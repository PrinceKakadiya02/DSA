/*
LeetCode 137
Single Number II

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ones = 0;   // stores bits appearing once
        int twos = 0;   // stores bits appearing twice

        for (int num : nums) {

            // update ones with bits not already in twos
            ones = (ones ^ num) & ~twos;

            // update twos with bits not already in ones
            twos = (twos ^ num) & ~ones;
        }

        // bits left in ones appear exactly once
        return ones;
    }
};

/*
Input:  nums = [2,2,3,2]
Output: 3

Input:  nums = [0,1,0,1,0,1,99]
Output: 99

Input:  nums = [5,5,5,7]
Output: 7
*/
