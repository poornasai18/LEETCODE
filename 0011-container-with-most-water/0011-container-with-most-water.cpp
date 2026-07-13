class Solution {
public:
    int maxArea(vector<int>& height) {

        // Left pointer starts from beginning
        int left = 0;

        // Right pointer starts from end
        int right = height.size() - 1;

        // Store maximum water found
        int maxWater = 0;

        // Continue until pointers meet
        while (left < right) {

            // Width between two lines
            int width = right - left;

            // Height is limited by the shorter line
            int currentHeight = min(height[left], height[right]);

            // Calculate current area
            int area = width * currentHeight;

            // Update maximum area
            maxWater = max(maxWater, area);

            // Move the pointer having smaller height
            // because only then can we possibly increase the area.
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        // Return maximum area found
        return maxWater;
    }
};