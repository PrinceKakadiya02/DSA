/*
LeetCode 66
Plus One

Time Complexity: O(n)
Space Complexity: O(1)   // Ignoring output vector
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int index = digits.size() - 1;  // index of the last digit
        int carry = 1;  // starting the carry with 1 bcz of the plus one

        while (index >= 0) { // iterate the whole array
            int sum = digits[index] + carry;    // calculate the sum
            digits[index] = sum % 10;  // place the least significant decimal
            carry = sum / 10;   //calculating the new carry
            index--;    // move to the left
            if (carry == 0) break;  // if no remaining carry break the loop
        }

        if (carry) {    // place the remaining carry at the begining of the array
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};

/*
Input: digits = [1,2,3]
Output: [1,2,4]

Input: digits = [4,3,2,1]
Output: [4,3,2,2]

Input: digits = [9]
Output: [1,0]

Input: digits = [9,9,9]
Output: [1,0,0,0]

Input: digits = [0]
Output: [1]
*/
