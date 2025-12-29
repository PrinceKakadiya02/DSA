/*
LeetCode 17
Letter Combinations of a Phone Number

Generates all possible letter combinations that a phone number could represent
using backtracking based on the digit-to-letter mapping.

Time Complexity: O(4^n)   // n = number of digits
Space Complexity: O(n)    // recursion stack
*/
class Solution {
private:
    void solve(string digits, string output, vector<string>& ans, int index, string mapping[]) {
        // base case : all digits are traversed return the output to ans
        if (index >= digits.length()) {
            ans.push_back(output);
            return;
        }

        // getting the digit from the keypad
        int number = digits[index] - '0';
        // getting the character from the number
        string value = mapping[number];

        for (int i = 0; i < value.length(); i++) {
            // add the chracter
            output.push_back(value[i]);
            // recursive call
            solve(digits, output, ans, index + 1, mapping);
            // backtrack
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) return ans;

        //array for storing the output
        string output;
        // tells which digit is currently converted into letters
        int index = 0;
        // array for number to digits
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, output, ans, index, mapping);
        return ans;
    }
};
