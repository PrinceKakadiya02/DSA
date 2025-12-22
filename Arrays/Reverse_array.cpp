/*
Reverse an Array

Time Complexity:  O(n)
Space Complexity: O(1)
*/

void reverse(vector<int>& nums){
    int start = 0;  // Starting index
    int end = nums.size() - 1;  // Ending index

    while(start < end){
        int temp = nums[start];   // Swap elements
        nums[start] = nums[end];
        nums[end] = temp;
        start++;    // Move start forward
        end--;  // Move end backward
    }
}
