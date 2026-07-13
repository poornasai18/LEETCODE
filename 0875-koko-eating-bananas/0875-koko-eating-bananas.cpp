class Solution {
public:

    // Function to check whether Koko can finish all bananas
    // within h hours using the given eating speed.
    bool canEat(vector<int>& piles, int h, int speed) {

        long long hours = 0;

        // Calculate total hours required for every pile
        for (int bananas : piles) {

            // Ceiling Division:
            // ceil(bananas / speed)
            //
            // Instead of using floating point,
            // use integer formula:
            //
            // (bananas + speed - 1) / speed
            hours += (bananas + speed - 1) / speed;
        }

        // Return true if Koko finishes within h hours
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        // Lowest possible eating speed
        int left = 1;

        // Highest possible eating speed
        int right = *max_element(piles.begin(), piles.end());

        // Store minimum valid speed
        int answer = right;

        // Binary Search on answer
        while (left <= right) {

            int mid = left + (right - left) / 2;

            // If Koko can finish at this speed
            if (canEat(piles, h, mid)) {

                answer = mid;

                // Try a smaller speed
                right = mid - 1;
            }
            else {

                // Speed is too slow
                left = mid + 1;
            }
        }

        return answer;
    }
};