class Solution {
public:
    string largestOddNumber(string num) {

        // Traverse the string from right to left.
        // We are looking for the last odd digit.
        for (int i = num.size() - 1; i >= 0; i--) {

            // Convert character digit to integer.
            // Example:
            // '5' - '0' = 5
            int digit = num[i] - '0';

            // Check if the digit is odd.
            if (digit % 2 == 1) {

                // Return substring from index 0
                // up to index i (inclusive).
                //
                // substr(start, length)
                // start = 0
                // length = i + 1
                //
                // Example:
                // num = "35427"
                // i = 4
                // return "35427"
                //
                // num = "35420"
                // i = 2
                // return "354"
                return num.substr(0, i + 1);
            }
        }

        // If no odd digit exists,
        // then it is impossible to form an odd number.
        return "";
    }
};