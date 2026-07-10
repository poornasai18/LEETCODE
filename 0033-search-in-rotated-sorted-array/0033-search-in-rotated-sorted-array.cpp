class Solution {
public:
    int search(vector<int>& nums, int target) {

        // Initialize the left and right pointers.
        int left = 0;
        int right = nums.size() - 1;

        // Perform Binary Search.
        while (left <= right) {

            // Find the middle index.
            int mid = left + (right - left) / 2;

            // If the target is found,
            // return its index.
            if (nums[mid] == target)
                return mid;

            // Check if the left half is sorted.
            if (nums[left] <= nums[mid]) {

                // If the target lies within the left sorted half,
                // search in the left half.
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                }

                // Otherwise, search in the right half.
                else {
                    left = mid + 1;
                }
            }

            // Otherwise, the right half is sorted.
            else {

                // If the target lies within the right sorted half,
                // search in the right half.
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                }

                // Otherwise, search in the left half.
                else {
                    right = mid - 1;
                }
            }
        }

        // Target not found.
        return -1;
    }
};