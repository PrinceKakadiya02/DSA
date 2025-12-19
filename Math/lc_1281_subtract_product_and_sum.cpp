/*
LeetCode 1281
Subtract the Product and Sum of Digits of an Integer

Time Complexity: O(d)
Space Complexity: O(1)
*/

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        int num = n;   // copy of n

        while (num > 0) {
            int digit = num % 10;  // get last digit
            num /= 10;             // remove last digit
            product *= digit;
            sum += digit;
        }

        return product - sum;
    }
};
