class Solution {
public:

    // Function to check whether all packages can be shipped
    // within the given number of days using 'capacity'
    bool canShip(vector<int>& weights, int days, int capacity) {

        int requiredDays = 1;      // At least one day is needed
        int currentLoad = 0;       // Current weight loaded on ship

        // Traverse every package
        for (int weight : weights) {

            // If adding this package exceeds the ship capacity,
            // send current ship and start a new day.
            if (currentLoad + weight > capacity) {
                requiredDays++;
                currentLoad = weight;
            }
            else {
                // Otherwise, load the package into current ship
                currentLoad += weight;
            }
        }

        // Return true if required days are within limit
        return requiredDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        // Lowest possible capacity
        int left = *max_element(weights.begin(), weights.end());

        // Highest possible capacity
        int right = accumulate(weights.begin(), weights.end(), 0);

        // Store the minimum valid answer
        int answer = right;

        // Binary Search on capacity
        while (left <= right) {

            int mid = left + (right - left) / 2;

            // If shipping is possible with current capacity
            if (canShip(weights, days, mid)) {

                answer = mid;      // Store current answer

                // Try finding even smaller capacity
                right = mid - 1;
            }
            else {
                // Capacity is too small
                left = mid + 1;
            }
        }

        return answer;
    }
};