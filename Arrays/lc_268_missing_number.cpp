/*
LeetCode 268
Missing Number

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        long long sum = 0;
        int n = nums.size();

        // expected sum of numbers from 0 to n
        long long expected = 1LL * n * (n + 1) / 2;

        // sum of given array
        for (int num : nums) {
            sum += num;
        }

        // missing number
        return expected - sum;
    }
};

/*
Input:  nums = [3,0,1]
Output: 2

Input:  nums = [0,1]
Output: 2

Input:  nums = [9,6,4,2,3,5,7,0,1]
Output: 8
*/
