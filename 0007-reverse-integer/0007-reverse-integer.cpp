class Solution {
public:
    int reverse(int x) {

        // Variable to store the reversed number
        int reversed = 0;

        // Continue until all digits are processed
        while (x != 0) {

            // Get the last digit
            int digit = x % 10;

            // Remove the last digit from x
            x /= 10;

            // Check for positive overflow
            // Example:
            // reversed = 214748365
            // reversed * 10 will exceed INT_MAX
            if (reversed > INT_MAX / 10)
                return 0;

            // If reversed == INT_MAX / 10,
            // adding a digit greater than 7 causes overflow
            if (reversed == INT_MAX / 10 && digit > 7)
                return 0;

            // Check for negative overflow
            // Example:
            // reversed = -214748365
            // reversed * 10 will go below INT_MIN
            if (reversed < INT_MIN / 10)
                return 0;

            // If reversed == INT_MIN / 10,
            // adding a digit smaller than -8 causes overflow
            if (reversed == INT_MIN / 10 && digit < -8)
                return 0;

            // Append the extracted digit
            reversed = reversed * 10 + digit;
        }

        // Return the reversed integer
        return reversed;
    }
};