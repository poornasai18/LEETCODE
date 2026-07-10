class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        // Step 1:
        // Find the first index from the end
        // where nums[i] < nums[i + 1].
        // This is called the pivot.
        int pivot = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2:
        // If no pivot is found,
        // the array is in descending order,
        // which is the last permutation.
        // Reverse the entire array to get
        // the first (smallest) permutation.
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3:
        // Find the first element from the end
        // that is greater than nums[pivot].
        int j = n - 1;

        while (nums[j] <= nums[pivot]) {
            j--;
        }

        // Step 4:
        // Swap the pivot with this element.
        swap(nums[pivot], nums[j]);

        // Step 5:
        // Reverse the suffix (elements after pivot)
        // to make it the smallest possible order.
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};