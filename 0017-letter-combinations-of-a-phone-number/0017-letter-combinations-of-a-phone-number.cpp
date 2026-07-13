class Solution {
public:

    // Store all possible answers
    vector<string> result;

    // Mapping of digits to letters
    vector<string> keypad = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    // Backtracking function
    void backtrack(string &digits, int index, string &current) {

        // Base Case:
        // If all digits are processed,
        // store the current combination.
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get letters corresponding to current digit
        string letters = keypad[digits[index] - '0'];

        // Try every possible letter
        for (char ch : letters) {

            // Choose current letter
            current.push_back(ch);

            // Recur for next digit
            backtrack(digits, index + 1, current);

            // Backtrack:
            // Remove last chosen character
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        // If input is empty, return empty answer
        if (digits.empty())
            return {};

        string current = "";

        backtrack(digits, 0, current);

        return result;
    }
};