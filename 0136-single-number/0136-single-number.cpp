class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // This variable will store the XOR of all elements.
        int result = 0;

        // Traverse every element in the array.
        for (int i = 0; i < nums.size(); i++) {

            // XOR the current element with the result.
            result ^= nums[i];
        }

        // Every number that appears twice cancels itself out.
        // The only remaining value is the single number.
        return result;
    }
};