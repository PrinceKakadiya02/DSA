/*
LeetCode 941
Valid Mountain Array

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int length = arr.size();
        int i = 0;

        // A mountain array must have at least 3 elements
        if (length < 3) return false;   

        while (i < length - 1 && arr[i] < arr[i + 1]) {   // check for ascending part
            i++;
        }

        if (i == 0 || i == length - 1) return false;   // peak cannot be first or last

        while (i < length - 1 && arr[i] > arr[i + 1]) {  // check for descending part
            i++;
        }
        // checking if after ascending and descending part if there are still elements remaining 
        return i == length - 1;
    }
};
