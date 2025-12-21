/*
LeetCode 33
Search in Rotated Sorted Array
Category: Binary Search

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // target found
            if (nums[mid] == target)
                return mid;

            // check if LEFT half is sorted
            if (nums[start] <= nums[mid]) {

                // target lies within the sorted left half
                if (nums[start] <= target && target < nums[mid])
                    end = mid - 1;   // move to left side
                else
                    start = mid + 1; // search in right half
            }
            // otherwise, RIGHT half must be sorted
            else {

                // target lies within the sorted right half
                if (nums[mid] < target && target <= nums[end])
                    start = mid + 1; // move to right side
                else
                    end = mid - 1;   // search in left half
            }
        }

        // target not found
        return -1;
    }
};
