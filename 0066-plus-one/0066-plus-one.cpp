class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        // Traverse the array from the last digit
        // because addition starts from the least significant digit.
        for (int i = digits.size() - 1; i >= 0; i--) {

            // If the current digit is less than 9,
            // simply increase it by 1 and return.
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // If the digit is 9,
            // it becomes 0 and we carry 1 to the previous digit.
            digits[i] = 0;
        }

        // If the loop finishes, it means every digit was 9.
        // Example:
        // 9      -> 10
        // 99     -> 100
        // 999    -> 1000

        // Insert 1 at the beginning of the array.
        digits.insert(digits.begin(), 1);

        return digits;
    }
};