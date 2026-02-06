/*
LeetCode 500
Keyboard Row

Time Complexity: O(n * m)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        unordered_map<char, int> rowMap;

        // map characters to their keyboard rows
        string row1 = "qwertyuiopQWERTYUIOP";
        string row2 = "asdfghjklASDFGHJKL";
        string row3 = "zxcvbnmZXCVBNM";

        for (char ch : row1) rowMap[ch] = 1;
        for (char ch : row2) rowMap[ch] = 2;
        for (char ch : row3) rowMap[ch] = 3;

        vector<string> result;

        for (string& word : words) {

            // determine row of first character
            int row = rowMap[word[0]];
            bool valid = true;

            // check if all characters belong to the same row
            for (char ch : word) {
                if (rowMap[ch] != row) {
                    valid = false;
                    break;
                }
            }

            if (valid) result.push_back(word);
        }

        return result;
    }
};


/*
Input:  ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]

Input:  ["omk"]
Output: []

Input:  ["adsdf","sfd"]
Output: ["adsdf","sfd"]
*/
