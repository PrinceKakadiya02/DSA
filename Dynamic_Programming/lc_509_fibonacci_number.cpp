/*
LeetCode 509
Fibonacci Number

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int fib(int n) {

        // base cases
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        // dp array to store fibonacci values
        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = 1;

        // build fibonacci values from bottom-up
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // nth fibonacci number
        return dp[n];
    }
};
