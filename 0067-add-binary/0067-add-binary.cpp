class Solution {
public:
    string addBinary(string a, string b) {

        // Start from the last character of both strings
        int i = a.size() - 1;
        int j = b.size() - 1;

        // Carry generated during binary addition
        int carry = 0;

        // Store the answer in reverse order
        string result = "";

        // Continue until both strings are processed
        // and there is no carry left.
        while (i >= 0 || j >= 0 || carry) {

            // Sum starts with the carry value
            int sum = carry;

            // If 'a' still has characters,
            // convert the current binary digit to integer
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            // If 'b' still has characters,
            // convert the current binary digit to integer
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            // Current binary digit is sum % 2
            result += (sum % 2) + '0';

            // Carry for the next iteration
            carry = sum / 2;
        }

        // The answer is built in reverse order,
        // so reverse it before returning.
        reverse(result.begin(), result.end());

        return result;
    }
};