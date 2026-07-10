class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        // Initialize the left and right pointers.
        int left = 0;
        int right = nums.size() - 1;

        // Perform Binary Search.
        while (left < right) {

            // Find the middle index.
            int mid = left + (right - left) / 2;

            // Make sure 'mid' is even.
            // This helps us compare pairs correctly.
            if (mid % 2 == 1) {
                mid--;
            }

            // If the current pair is valid,
            // the single element lies on the right.
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            }

            // Otherwise, the single element is
            // at mid or on the left side.
            else {
                right = mid;
            }
        }

        // When left == right,
        // it points to the single element.
        return nums[left];
    }
};