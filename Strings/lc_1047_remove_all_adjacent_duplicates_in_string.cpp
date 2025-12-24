/*
LeetCode 1047
Remove All Adjacent Duplicates in String

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0;  // index for the result string (acts like a stack)

        // iterate through each character
        for (int j = 0; j < s.size(); j++) {
            s[i] = s[j];  // place current character

            // if adjacent characters are same, remove both
            if (i > 0 && s[i] == s[i - 1]) {
                i -= 2;   // pop last two characters
            }

            i++;    // move to next position
        }

        // return valid portion of the string
        return s.substr(0, i);
    }
};

/*
LeetCode 1047
Remove All Adjacent Duplicates in String

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";  // acts like a stack

        // iterate through each character
        for (char c : s) {

            // if top matches current, remove it
            if (!res.empty() && res.back() == c)
                res.pop_back();
            else
                res.push_back(c);  // otherwise, add character
        }

        return res;
    }
};

/*
LeetCode 1047
Remove All Adjacent Duplicates in String

Time Complexity: O(n²)   // due to erase operations
Space Complexity: O(1)
*/

class Solution {
public:
    string removeDuplicates(string s) {
        int k = 1;

        // iterate through string and remove adjacent duplicates
        while (k < s.size()) {

            // if adjacent characters are equal
            if (s[k] == s[k - 1]) {
                s.erase(k - 1, 2);  // remove both duplicates
                k--;    // move back to recheck

                // ensure k stays within bounds
                if (k == 0)
                    k = 1;
            }
            else {
                k++;    // move forward
            }
        }

        return s;
    }
};
