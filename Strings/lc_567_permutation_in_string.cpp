/*
LeetCode 567
Permutation in String

Time Complexity: O(26 * n) ~ O(n)
Space Complexity: O(26) ~ O(1)
*/

class Solution {
public:
    // check if two frequency arrays are equal
    bool checkEqual(int a[26], int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};
        for (char c : s1) count1[c - 'a']++;  // frequency of s1

        int windowSize = s1.length();
        int count2[26] = {0};

        // initialize first window in s2
        int i = 0;
        while (i < windowSize && i < s2.length()) {
            count2[s2[i] - 'a']++;
            i++;
        }
        if (checkEqual(count1, count2)) return true;

        // slide the window
        while (i < s2.length()) {
            count2[s2[i] - 'a']++;                     // add new char into frequency of s2
            count2[s2[i - windowSize] - 'a']--;       // remove old char into frequency of s2
            i++;

            if (checkEqual(count1, count2)) return true;
        }

        return false;
    }
};
