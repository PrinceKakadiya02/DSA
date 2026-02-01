/*
LeetCode 164
Maximum Gap

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {

        int n = nums.size();
        if (n < 2) return 0;

        // find global minimum and maximum
        int minValue = *min_element(nums.begin(), nums.end());
        int maxValue = *max_element(nums.begin(), nums.end());

        if (minValue == maxValue) return 0; // if both are same then returning 0 bcz no difference all elements are the same 

        // minimum possible bucket size (ceiling)
        int bucketSize = ceil((double)(maxValue - minValue) / (n - 1));  // size of each bucket
        int bucketCount = (maxValue - minValue) / bucketSize + 1;   // no of buckets required for storing the min max value

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        vector<bool> used(bucketCount, false);

        // place numbers into buckets
        for (int num : nums) {
            int idx = (num - minValue) / bucketSize;
            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
            used[idx] = true;
        }

        int prevMax = minValue;
        int maxGap = 0;

        // compute maximum gap between consecutive non-empty buckets
        // to find the gap finding the immediate full bucket and subtrct the max of previous by min of next immediate full bucket
        for (int i = 0; i < bucketCount; i++) {
            if (!used[i]) continue;

            maxGap = max(maxGap, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }

        return maxGap;
    }
};

/*
LeetCode 164
Maximum Gap (Sorting Approach)

Time Complexity: O(n log n)
Space Complexity: O(1)  // ignoring sort's internal space
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {

        int n = nums.size();
        if (n < 2) return 0;

        // sort the array
        sort(nums.begin(), nums.end());

        int maxGap = 0;

        // find maximum difference between consecutive elements
        for (int i = 1; i < n; i++) {
            maxGap = max(maxGap, nums[i] - nums[i - 1]);
        }

        return maxGap;
    }
};


/*
Input:  nums = [3,6,9,1]
Output: 3

Input:  nums = [10]
Output: 0

Input:  nums = [1,1,1,1]
Output: 0

Input:  nums = [1,10000000]
Output: 9999999
*/
