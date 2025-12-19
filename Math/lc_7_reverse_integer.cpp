/*
LeetCode 7
Reverse Integer

Time Complexity: O(d)
Space Complexity: O(1)
*/
class Solution {
public:
    int reverse(int num) {
    int ans = 0;
    while (num != 0){
        int digit = num %10;   // get last digit

        // check overflow
        if (( ans > INT_MAX / 10) || ( ans < INT_MIN/10)){
            return 0;
        }
        ans = (ans *10) + digit;
        num = num /10;
    }
    return ans;
    }
};