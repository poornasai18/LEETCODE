class Solution {
public:
    string reverseWords(string s) {

        // This string will store the final answer.
        string ans = "";

        // Start from the last character of the string.
        int i = s.length() - 1;

        // Traverse until the beginning of the string.
        while (i >= 0) {

            // -----------------------------------------
            // Step 1: Skip all extra spaces.
            // Example:
            // "hello   "
            //          ^
            // Move left until reaching 'o'
            // -----------------------------------------
            while (i >= 0 && s[i] == ' ')
                i--;

            // If all characters were spaces, stop.
            if (i < 0)
                break;

            // -----------------------------------------
            // Step 2: Find the ending index of the word.
            // -----------------------------------------
            int end = i;

            // -----------------------------------------
            // Step 3: Move left until a space is found.
            // This gives the starting index of the word.
            // -----------------------------------------
            while (i >= 0 && s[i] != ' ')
                i--;

            // Word starts at i+1 and ends at 'end'.
            int start = i + 1;

            // -----------------------------------------
            // Step 4: Add this word to the answer.
            // -----------------------------------------
            ans += s.substr(start, end - start + 1);

            // -----------------------------------------
            // Step 5: Skip spaces before the next word.
            // If another word exists, add one space.
            // -----------------------------------------
            while (i >= 0 && s[i] == ' ')
                i--;

            if (i >= 0)
                ans += " ";
        }

        // Return the reversed sentence.
        return ans;
    }
};