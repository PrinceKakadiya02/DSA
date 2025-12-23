/*
LeetCode 151
Reverse Words in a String

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    // reverse characters in range [start, end]
    void reverseRange(string& s, int start, int end) {
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseWords(string s) {
        int n = s.size();
        int write = 0;   // index to write cleaned string
        int i = 0;

        // remove extra spaces
        while (i < n) {
            // skip spaces
            while (i < n && s[i] == ' ') i++;

            if (i >= n) break;

            // add single space between words
            if (write > 0) s[write++] = ' ';

            // copy characters of the word
            while (i < n && s[i] != ' ') {
                s[write++] = s[i++];
            }
        }

        // resize to cleaned length
        s.resize(write);

        // reverse entire string
        reverseRange(s, 0, s.size() - 1);

        // reverse each word
        int start = 0;
        for (int k = 0; k <= s.size(); k++) {
            if (k == s.size() || s[k] == ' ') {
                reverseRange(s, start, k - 1);
                start = k + 1;
            }
        }

        return s;
    }
};
