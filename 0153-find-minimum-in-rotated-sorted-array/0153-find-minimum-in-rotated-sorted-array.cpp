class Solution {
public:
    int findMin(vector<int>& nums) {

        // Initialize the left and right pointers.
        int left = 0;
        int right = nums.size() - 1;

        // Perform Binary Search.
        while (left < right) {

            // Find the middle index.
            int mid = left + (right - left) / 2;

            // If the middle element is greater than
            // the rightmost element, the minimum
            // must be in the right half.
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }

            // Otherwise, the minimum lies in the
            // left half (including the middle element).
            else {
                right = mid;
            }
        }

        // When left == right,
        // it points to the minimum element.
        return nums[left];
    }
};