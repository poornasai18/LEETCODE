class Solution {
public:

    // Function to find the first occurrence of the target.
    int findFirst(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        int first = -1;

        // Perform Binary Search.
        while (left <= right) {

            // Find the middle index.
            int mid = left + (right - left) / 2;

            // If target is found,
            // store the index and continue searching
            // on the left side to find an earlier occurrence.
            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;
            }

            // If current value is smaller,
            // search in the right half.
            else if (nums[mid] < target) {
                left = mid + 1;
            }

            // Otherwise search in the left half.
            else {
                right = mid - 1;
            }
        }

        return first;
    }

    // Function to find the last occurrence of the target.
    int findLast(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        int last = -1;

        // Perform Binary Search.
        while (left <= right) {

            // Find the middle index.
            int mid = left + (right - left) / 2;

            // If target is found,
            // store the index and continue searching
            // on the right side to find the last occurrence.
            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;
            }

            // If current value is smaller,
            // search in the right half.
            else if (nums[mid] < target) {
                left = mid + 1;
            }

            // Otherwise search in the left half.
            else {
                right = mid - 1;
            }
        }

        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        // Find the first and last occurrences.
        int first = findFirst(nums, target);
        int last = findLast(nums, target);

        // Return the result.
        return {first, last};
    }
};