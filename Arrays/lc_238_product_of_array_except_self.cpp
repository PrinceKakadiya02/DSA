/*
LeetCode 238
Product of Array Except Self

Time Complexity: O(n)
Space Complexity: O(1)  // excluding output array
*/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> ans(n, 1);

        int left = 1;

        // prefix product
        for (int i = 0; i < n; i++)
        {
            ans[i] *= left;
            left *= nums[i];
        }

        int right = 1;

        // suffix product
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};

/*
Input:  nums = [1,2,3,4]
Output: [24,12,8,6]

Input:  nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/