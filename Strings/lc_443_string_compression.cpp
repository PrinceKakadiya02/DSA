/*
LeetCode 443
String Compression

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;  // read pointer for unique character
        int len = 0;    // write pointer
        int n = chars.size();

        // traverse the character array
        while (i < n) {
            int j = i + 1;   // read pointer for the reapeated character

            // count consecutive repeating characters
            while (j < n && chars[i] == chars[j]) {
                j++;
            }

            // write the character
            chars[len++] = chars[i];

            int count = j - i; // get the no of repeated characters 
            // write count if greater than 1
            if (count > 1) {
                string s = to_string(count);
                for (char ch : s) {
                    chars[len++] = ch; // storing the count
                }
            }

            // move to next character
            i = j;
        }

        // return new length
        return len;
    }
};

