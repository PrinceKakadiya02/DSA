/*
LeetCode 88
Merge Sorted Array

Time Complexity: O(m + n)
Space Complexity: O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;           // last index of valid elements in nums1
        int j = n - 1;           // last index of nums2
        int idx = m + n - 1;     // last index of nums1

        // if nums2 is empty, nothing to merge
        if (n == 0) return;

        // merge from the end to avoid overwriting nums1
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {  // place element from nums1
                nums1[idx] = nums1[i];
                i--;
            } else {
                nums1[idx] = nums2[j]; // place element from the nums2
                j--;
            }
            idx--;
        }

        // copy remaining elements of nums1 (if any)
        while (i >= 0) {
            nums1[idx] = nums1[i];
            i--;
            idx--;
        }

        // copy remaining elements of nums2 (if any)
        while (j >= 0) {
            nums1[idx] = nums2[j];
            j--;
            idx--;
        }
    }
};
