class Solution {
public:
    int divide(int dividend, int divisor) {

        // Special overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert to long long to avoid overflow
        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long quotient = 0;

        // Continue until dividend becomes smaller than divisor
        while (dvd >= dvs) {

            long long temp = dvs;
            long long multiple = 1;

            // Double divisor until it exceeds dividend
            while ((temp << 1) <= dvd) {
                temp <<= 1;        // temp = temp * 2
                multiple <<= 1;    // multiple = multiple * 2
            }

            // Subtract largest possible multiple
            dvd -= temp;

            // Add corresponding quotient value
            quotient += multiple;
        }

        // Determine sign of result
        if ((dividend < 0) ^ (divisor < 0))
            quotient = -quotient;

        return (int)quotient;
    }
};