/*
LeetCode 26
Remove Duplicates from Sorted Array
    Remove duplicates from a sorted array in-place such that
    each unique element appears only once.
    Return the number of unique elements.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // index to place next unique element
        int k = 1;

        // traverse array from second element
        for (int i = 1; i < nums.size(); i++) {

            // if current element is different from previous
            if (nums[i - 1] != nums[i]) {

                // place unique element at index k
                nums[k] = nums[i];
                k++;
            }
        }

        // k represents count of unique elements
        return k;
    }
};
