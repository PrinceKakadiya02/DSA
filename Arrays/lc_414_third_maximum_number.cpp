/*
LeetCode 414
Third Maximum Number

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {

        // use long long to safely handle INT_MIN cases
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int num : nums) {

            // skip duplicates
            if (num == first || num == second || num == third) continue;

            if (num > first) {
                third = second;
                second = first;
                first = num;
            }
            else if (num > second) {
                third = second;
                second = num;
            }
            else if (num > third) {
                third = num;
            }
        }

        // if third maximum doesn't exist, return the maximum
        return (third == LLONG_MIN) ? first : third;
    }
};


/*
Input:  nums = [3,2,1]
Output: 1

Input:  nums = [1,2]
Output: 2

Input:  nums = [2,2,3,1]
Output: 1

Input:  nums = [1,2,2,5,3,5]
Output: 2
*/
