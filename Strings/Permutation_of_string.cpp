/*
String Permutations

Generates all permutations of a given string using backtracking
by swapping characters position-wise.

Time Complexity: O(n! * n)
Space Complexity: O(n)   // recursion stack
*/

class Solution {
private:
    void solve(string s, vector<string>& ans, int index) {
        // Base case: permutation completed
        if (index >= s.size()) {
            ans.push_back(s);
            return;
        }

        // Try all possibilities for current index
        for (int j = index; j < s.size(); j++) {
            swap(s[index], s[j]);       // choose the element for index position
            solve(s, ans, index + 1);    // recurse
            swap(s[index], s[j]);       // backtrack
        }
    }

public:
    vector<string> permuteString(string s) {
        vector<string> ans;
        solve(s, ans, 0);
        return ans;
    }
};
