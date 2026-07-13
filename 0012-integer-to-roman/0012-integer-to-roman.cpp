class Solution {
public:
    string intToRoman(int num) {

        // Integer values in descending order
        vector<int> values = {
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4, 1
        };

        // Corresponding Roman symbols
        vector<string> symbols = {
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV", "I"
        };

        string answer = "";

        // Traverse all Roman values
        for (int i = 0; i < values.size(); i++) {

            // Keep taking the current value while possible
            while (num >= values[i]) {

                // Append corresponding Roman symbol
                answer += symbols[i];

                // Reduce the number
                num -= values[i];
            }
        }

        return answer;
    }
};