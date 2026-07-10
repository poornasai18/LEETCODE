class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        // Sort the array so that we can use the two-pointer technique.
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Initialize the closest sum using the first three elements.
        int closestSum = nums[0] + nums[1] + nums[2];

        // Fix one element at a time.
        for (int i = 0; i < n - 2; i++) {

            // Left pointer starts just after the fixed element.
            int left = i + 1;

            // Right pointer starts at the end of the array.
            int right = n - 1;

            // Continue until both pointers meet.
            while (left < right) {

                // Calculate the current sum.
                int currentSum = nums[i] + nums[left] + nums[right];

                // If the current sum is closer to the target,
                // update the closest sum.
                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                // If we found the exact target,
                // return immediately.
                if (currentSum == target) {
                    return currentSum;
                }

                // If the current sum is smaller than the target,
                // move the left pointer to increase the sum.
                else if (currentSum < target) {
                    left++;
                }

                // Otherwise, move the right pointer
                // to decrease the sum.
                else {
                    right--;
                }
            }
        }

        // Return the closest sum found.
        return closestSum;
    }
};