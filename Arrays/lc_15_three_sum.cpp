/*
LeetCode 15
3Sum

Time Complexity: O(n^2)
Space Complexity: O(1)   // ignoring output array
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());   // sort array
        int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n - 2; i++) {

            // skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int L = i + 1;
            int R = n - 1;

            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];

                if (sum > 0) {
                    R--;    // decrease sum
                }
                else if (sum < 0) {
                    L++;    // increase sum
                }
                else {
                    // valid triplet
                    res.push_back({nums[i], nums[L], nums[R]});
                    L++;
                    R--;

                    // skip duplicate second element
                    while (L < R && nums[L] == nums[L - 1]) L++;

                    // skip duplicate third element
                    while (L < R && nums[R] == nums[R + 1]) R--;
                }
            }
        }
        return res;
    }
};

/*
Input:
nums = [-1,0,1,2,-1,-4]
Output:
[[-1,-1,2],[-1,0,1]]

Input:
nums = [0,1,1]
Output:
[]

Input:
nums = [0,0,0]
Output:
[[0,0,0]]
*/
