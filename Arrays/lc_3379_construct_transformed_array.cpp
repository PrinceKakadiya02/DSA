/*
LeetCode
Construct Transformed Array

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {

            // if value is zero, index remains the same
            if (nums[i] == 0) {
                result[i] = nums[i];
            }
            else {
                // calculate new index using circular movement
                int newIdx = (i + nums[i]) % n;

                // handle negative index wrapping
                if (newIdx < 0) newIdx += n;

                result[i] = nums[newIdx];
            }
        }

        return result;
    }
};


/*
Input:  nums = [1,2,3,4]
Output: [2,4,2,4]

Input:  nums = [0,-1,2]
Output: [0,0,2]

Input:  nums = [-1,-2,-3]
Output: [-3,-1,-2]
*/
