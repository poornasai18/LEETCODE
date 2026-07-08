class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always perform binary search on the smaller array.
        // This keeps the complexity as O(log(min(m,n))).
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        // Binary search range on nums1
        int low = 0;
        int high = m;

        // Total number of elements that should be on the left side.
        // +1 handles both even and odd length cases.
        int leftSize = (m + n + 1) / 2;

        while(low <= high)
        {
            // Partition index in nums1
            int cut1 = (low + high) / 2;

            // Partition index in nums2
            // Together they should make leftSize elements.
            int cut2 = leftSize - cut1;

            //---------------------------------------------------
            // Find boundary elements around both partitions.
            //---------------------------------------------------

            // Left element of nums1
            // If partition is at beginning,
            // use negative infinity.
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];

            // Right element of nums1
            // If partition is at end,
            // use positive infinity.
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];

            // Left element of nums2
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            // Right element of nums2
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            //---------------------------------------------------
            // Check if we found the correct partition.
            //
            // All elements in left half should be
            // <= all elements in right half.
            //---------------------------------------------------
            if(l1 <= r2 && l2 <= r1)
            {
                // Total number of elements
                if((m + n) % 2 == 1)
                {
                    // Odd length
                    // Median is the largest element on left side.
                    return max(l1, l2);
                }
                else
                {
                    // Even length
                    // Median is average of
                    // max(left) and min(right).
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }

            //---------------------------------------------------
            // Partition is too far right in nums1.
            //
            // Example:
            // l1 > r2
            //
            // Move binary search to left.
            //---------------------------------------------------
            else if(l1 > r2)
            {
                high = cut1 - 1;
            }

            //---------------------------------------------------
            // Partition is too far left.
            //
            // Example:
            // l2 > r1
            //
            // Move binary search to right.
            //---------------------------------------------------
            else
            {
                low = cut1 + 1;
            }
        }

        // This line is never reached because
        // the input guarantees valid sorted arrays.
        return 0.0;
    }
};