class Solution {
public:
    int mySqrt(int x) {

        // Special case:
        // The square root of 0 and 1 is the number itself.
        if (x == 0 || x == 1)
            return x;

        // Binary Search range:
        // Square root of x always lies between 1 and x.
        int left = 1;
        int right = x;

        // Variable to store the answer.
        int ans = 0;

        // Perform Binary Search.
        while (left <= right) {

            // Find the middle element.
            int mid = left + (right - left) / 2;

            // Use long long to avoid integer overflow
            // when calculating mid * mid.
            long long square = 1LL * mid * mid;

            // If mid * mid equals x,
            // then mid is the exact square root.
            if (square == x) {
                return mid;
            }

            // If mid * mid is less than x,
            // then mid can be the answer.
            else if (square < x) {
                ans = mid;
                left = mid + 1;
            }

            // Otherwise search in the left half.
            else {
                right = mid - 1;
            }
        }

        // Return the floor value of sqrt(x).
        return ans;
    }
};