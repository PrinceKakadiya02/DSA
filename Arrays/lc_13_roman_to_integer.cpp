/*
LeetCode 13
Roman to Integer

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int romanToInt(string s) {

        vector<int> values;

        // convert each Roman character to its integer value
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I') values.push_back(1);
            else if (s[i] == 'V') values.push_back(5);
            else if (s[i] == 'X') values.push_back(10);
            else if (s[i] == 'L') values.push_back(50);
            else if (s[i] == 'C') values.push_back(100);
            else if (s[i] == 'D') values.push_back(500);
            else if (s[i] == 'M') values.push_back(1000);
        }

        int result = 0;

        // subtract if smaller value appears before a larger one
        for (int i = 0; i < values.size() - 1; i++) {
            if (values[i] < values[i + 1])
                result -= values[i];
            else
                result += values[i];
        }

        // add the last value
        result += values.back();

        return result;
    }
};


/*
LeetCode 13
Roman to Integer

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100},
            {'D', 500}, {'M', 1000}
        };

        int res = 0;

        for (int i = 0; i < s.size(); i++) {

            // subtract if smaller value comes before a larger one
            if (i + 1 < s.size() && mp[s[i]] < mp[s[i + 1]])
                res -= mp[s[i]];
            else
                res += mp[s[i]];
        }

        return res;
    }
};


/*
Input: s = "III"
Output: 3

Input: s = "IV"
Output: 4

Input: s = "IX"
Output: 9

Input: s = "LVIII"
Output: 58

Input: s = "MCMXCIV"
Output: 1994
*/
