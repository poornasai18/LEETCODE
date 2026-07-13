class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.length();

        // Skip all leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // If string contains only spaces
        if (i == n)
            return 0;

        // Default sign is positive
        int sign = 1;

        // Check for '+' or '-'
        if (s[i] == '+') {
            i++;
        }
        else if (s[i] == '-') {
            sign = -1;
            i++;
        }

        // Store the result in long long to safely detect overflow
        long long result = 0;

        // Read digits until a non-digit is found
        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // Build the number
            result = result * 10 + digit;

            // Handle overflow immediately
            if (sign == 1 && result > INT_MAX)
                return INT_MAX;

            if (sign == -1 && -result < INT_MIN)
                return INT_MIN;

            i++;
        }

        // Apply sign and return answer
        return (int)(sign * result);
    }
};