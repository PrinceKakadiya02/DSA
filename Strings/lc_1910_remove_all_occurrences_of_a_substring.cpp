/*
LeetCode 1910
Remove All Occurrences of a Substring

Time Complexity: O(n * m)   // n = s.size(), m = part.size()
Space Complexity: O(n)
*/

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res = "";
        int m = part.size();

        // build result string and remove part when found
        for (char c : s) {
            res.push_back(c);

            // check if the last m characters match part
            if (res.size() >= m &&
                res.substr(res.size() - m) == part) {  //check if last m charcters are match to the part
                res.erase(res.size() - m);  // remove matched part
            }
        }

        return res;
    }
};

class Solution {
public:
    string removeOccurrences(string s, string part) {
        // repeatedly erase part while it exists in s
        while (s.size() && s.find(part) < s.size()) {
            s.erase(s.find(part), part.size());
        }
        return s;
    }
};
