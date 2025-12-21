/*
LeetCode: 189
Rotate Array

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();   // Store the size of the array
        vector<int> rotated(n);   // Extra array to store rotated elements

        k = k % n;   // Handle cases where k >= n

        // Place each element at its rotated position
        for (int i = 0; i < n; i++) {
            rotated[(i + k) % n] = nums[i];
        }

        // Copy rotated array back to original array
        for (int i = 0; i < n; i++) {
            nums[i] = rotated[i];
        } 
    }
};
