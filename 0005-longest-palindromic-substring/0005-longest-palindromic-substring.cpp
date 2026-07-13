class Solution {
public:

    // Function to expand around the given center
    // left and right represent the current palindrome boundaries
    int expandFromCenter(string &s, int left, int right) {

        // Keep expanding while:
        // 1. left index is valid
        // 2. right index is valid
        // 3. Characters are equal
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        // When loop stops, palindrome exceeded by one position on both sides.
        // Hence actual palindrome length is:
        return right - left - 1;
    }

    string longestPalindrome(string s) {

        // If string has only one character, return it
        if (s.size() <= 1)
            return s;

        int start = 0;   // Starting index of longest palindrome
        int end = 0;     // Ending index of longest palindrome

        // Try every character as the center
        for (int i = 0; i < s.size(); i++) {

            // Case 1: Odd length palindrome
            int len1 = expandFromCenter(s, i, i);

            // Case 2: Even length palindrome
            int len2 = expandFromCenter(s, i, i + 1);

            // Take maximum length
            int len = max(len1, len2);

            // If current palindrome is longer than previous best
            if (len > end - start + 1) {

                // Calculate new starting index
                start = i - (len - 1) / 2;

                // Calculate new ending index
                end = i + len / 2;
            }
        }

        // Return longest palindromic substring
        return s.substr(start, end - start + 1);
    }
};