/*
Find Array Sum
(Add two numbers represented as arrays)

Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

class Solution {
public:
    vector<int> findArraySum(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        int i = nums1.size() - 1;
        int j = nums2.size() - 1;
        int carry = 0;
        int sum = 0;

        // add digits from right to left
        while (i >= 0 || j >= 0 || carry) {
            sum = carry;

            if (i >= 0) {   // if nums1 have remaining left digits
                sum += nums1[i];
                i--;
            }

            if (j >= 0) {   // if nums2 have remaining left digits
                sum += nums2[j];
                j--;
            }

            ans.push_back(sum % 10);
            carry = sum / 10;
        }

        // reverse to get correct order
        reverse(ans.begin(), ans.end());

        return ans;
    }
}
