/*
LeetCode 27
Remove Element

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int i = 0;

        while (i < size) {

            // if current element matches val, replace it with last element
            if (nums[i] == val) {
                nums[i] = nums[size - 1];  
                size--; // val found decrease the size of array
            }
            else {
                i++;  // val not found check the next element
            }
        }

        return size;
    }
};

/*
LeetCode 27
Remove Element (Swap Method)

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;             // count of removed elements
        int size = nums.size();

        for (int i = 0; i < size - k; i++) {

            // if current element equals val, swap it with last unprocessed element
            if (nums[i] == val) {
                swap(nums[i], nums[size - k - 1]);
                k++;
                i--;   // stay at current index to check swapped value
            }
        }

        return size - k;  // new length after removal
    }
};


/*
Input: nums = [3,2,2,3], val = 3
Output: 2
(nums can be [2,2])

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5
(nums can be [0,1,3,0,4])

Input: nums = [], val = 1
Output: 0

Input: nums = [1,1,1], val = 1
Output: 0
*/

