    /*
LeetCode 75
Sort Colors

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int red = 0;    // next position for 0
        int white = 0;  // current index
        int blue = nums.size() - 1;  // next position for 2

        while (white <= blue) {

            if (nums[white] == 0) {
                swap(nums[white], nums[red]); // move 0 to the front
                red++;
                white++;
            } 
            else if (nums[white] == 1) {
                white++; // 1 is in correct place
            } 
            else { // nums[white] == 2
                swap(nums[white], nums[blue]); // move 2 to the end
                blue--;
            }
        }
    }
};


/*
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Input: nums = [2,0,1]
Output: [0,1,2]

Input: nums = [0]
Output: [0]

Input: nums = [1]
Output: [1]
*/

