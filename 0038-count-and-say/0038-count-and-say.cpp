class Solution {
public:
    string countAndSay(int n) {

        // Base case
        string result = "1";

        // Generate terms from 2 to n
        for (int i = 2; i <= n; i++) {

            string current = "";
            int count = 1;

            // Traverse previous result
            for (int j = 0; j < result.size(); j++) {

                // Count consecutive same digits
                while (j + 1 < result.size() &&
                       result[j] == result[j + 1]) {
                    count++;
                    j++;
                }

                // Append count
                current += to_string(count);

                // Append digit
                current += result[j];

                // Reset count
                count = 1;
            }

            // Current becomes next term
            result = current;
        }

        return result;
    }
};