class Solution {
public:
    int strStr(string haystack, string needle) {

        // Length of both strings
        int n = haystack.size();
        int m = needle.size();

        // Traverse every possible starting position
        // where 'needle' can fit inside 'haystack'
        for (int i = 0; i <= n - m; i++) {

            // Assume the substring matches
            bool found = true;

            // Compare every character of needle
            for (int j = 0; j < m; j++) {

                // If any character doesn't match,
                // this starting position is invalid
                if (haystack[i + j] != needle[j]) {
                    found = false;
                    break;
                }
            }

            // If all characters matched,
            // return the starting index
            if (found)
                return i;
        }

        // Needle is not present in haystack
        return -1;
    }
};