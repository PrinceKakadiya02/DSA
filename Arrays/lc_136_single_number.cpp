/*
LeetCode 136
Single Number

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        // XOR of same numbers cancels out (a ^ a = 0)
        // XOR with 0 gives the number itself (a ^ 0 = a)
        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};

/*
Input:
nums = [2,2,1]
Output:
1

Input:
nums = [4,1,2,1,2]
Output:
4

Input:
nums = [1]
Output:
1
*/
