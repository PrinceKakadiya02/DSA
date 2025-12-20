/*
LeetCode 852
Peak Index in a Mountain Array
    - it is an array where one half of the array is in ascending and other part is n descending part

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2; // upadting the mid 

            if (arr[mid] <= arr[mid + 1]) {  // mid is in ascending part, might be a peak
                start = mid + 1;    // check right part
            } else {  // mid is in descending part, peak will be at the end of ascendind part
                end = mid;   // peak is on left side
            }
        }
        
        return start; // peak index
    }
};
