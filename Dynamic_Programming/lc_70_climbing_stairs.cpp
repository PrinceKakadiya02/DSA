/*
LeetCode 70
Climbing Stairs
    You can climb 1 or 2 steps at a time.
    Return the number of distinct ways to reach the top.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int climbStairs(int n) {

        // if only one step, only one way
        if (n == 1)
            return 1;

        // dp[i] stores number of ways to reach step i
        vector<int> dp(n + 1);

        // base cases
        dp[0] = 1;
        dp[1] = 1;

        // compute ways for each step
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // ways to reach nth step
        return dp[n];
    }
};
