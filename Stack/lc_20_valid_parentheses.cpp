/*
LeetCode 20
Valid Parentheses

Approach: Stack

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        // traverse each character in the string
        for (char c : s) {

            // push opening brackets onto stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                // no matching opening bracket
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                // check for matching pair
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // stack must be empty for valid parentheses
        return st.empty();
    }
};

/*
LeetCode 20
Valid Parentheses (Using Unordered Map)

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        stack<char> st;

        for (char c : s) {
            if (mp.find(c) != mp.end()) { // closing bracket
                if (st.empty() || st.top() != mp[c]) {
                    return false;
                }
                st.pop();
            } else {
                st.push(c); // opening bracket
            }
        }

        return st.empty();
    }
};


/*
Input: s = "()"
Output: true

Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false

Input: s = "([)]"
Output: false

Input: s = "{[]}"
Output: true
*/
