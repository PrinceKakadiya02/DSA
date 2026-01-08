/*
LeetCode 28
Find the Index of the First Occurrence in a String

Time Complexity: O(n * m)
Space Complexity: O(1)
*/

class Solution {
public:
    int strStr(string haystack, string needle) {

        // edge case: empty needle
        if (needle.empty()) return 0;

        int n = haystack.length();
        int m = needle.length();

        // check each possible starting index
        for (int i = 0; i <= n - m; i++) {
            if (haystack.substr(i, m) == needle)
                return i;
        }

        return -1;
    }
};

/*
Input: haystack = "sadbutsad", needle = "sad"
Output: 0

Input: haystack = "leetcode", needle = "leeto"
Output: -1

Input: haystack = "hello", needle = "ll"
Output: 2

Input: haystack = "aaaaa", needle = "bba"
Output: -1

Input: haystack = "abc", needle = ""
Output: 0
*/
