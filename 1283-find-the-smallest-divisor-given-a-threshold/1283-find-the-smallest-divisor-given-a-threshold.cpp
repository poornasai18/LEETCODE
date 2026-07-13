class Solution {
public:

    // Function to check whether a given divisor
    // satisfies the threshold condition
    bool isPossible(vector<int>& nums, int threshold, int divisor) {

        long long sum = 0;

        // Calculate:
        // ceil(num/divisor) for every element
        for (int num : nums) {

            // Ceiling Division:
            // ceil(num/divisor)
            //
            // Formula:
            // (num + divisor - 1) / divisor
            sum += (num + divisor - 1) / divisor;
        }

        // Return true if total sum is within threshold
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        // Lowest possible divisor
        int left = 1;

        // Highest possible divisor
        int right = *max_element(nums.begin(), nums.end());

        // Store minimum valid divisor
        int answer = right;

        // Binary Search
        while (left <= right) {

            int mid = left + (right - left) / 2;

            // If current divisor works
            if (isPossible(nums, threshold, mid)) {

                answer = mid;

                // Try finding an even smaller divisor
                right = mid - 1;
            }
            else {

                // Divisor is too small
                left = mid + 1;
            }
        }

        return answer;
    }
};