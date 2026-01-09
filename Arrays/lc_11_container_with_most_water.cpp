/*
LeetCode 11
Container With Most Water

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxArea(vector<int>& height) {

        int maxArea = 0;
        int start = 0, end = height.size() - 1;

        while (start < end) {

            int area = (end - start) * min(height[start], height[end]);  // calculate the area between the two pointers
            maxArea = max(maxArea, area);

            if (height[start] > height[end]) {  // move the pointer with smaller height
                end--;
            } else {  
                start++;
            }
        }

        return maxArea;
    }
};


/*
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49

Input: height = [1,1]
Output: 1

Input: height = [4,3,2,1,4]
Output: 16

Input: height = [1,2,1]
Output: 2

Input: height = [1,3,2,5,25,24,5]
Output: 24
*/
