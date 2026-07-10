class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        // 'k' represents the index where the next valid element
        // should be placed.
        int k = 0;

        // Traverse every element in the array.
        for (int i = 0; i < nums.size(); i++) {

            // If the current element is NOT equal to 'val',
            // keep it in the array.
            if (nums[i] != val) {

                // Place the valid element at index 'k'.
                nums[k] = nums[i];

                // Move to the next position for future valid elements.
                k++;
            }

            // If nums[i] == val, simply ignore it.
        }

        // Return the number of remaining elements.
        return k;
    }
};