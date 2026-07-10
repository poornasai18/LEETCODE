class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // Store the minimum stock price seen so far.
        // Initially, the first day's price is the minimum.
        int minPrice = prices[0];

        // Variable to store the maximum profit.
        int maxProfit = 0;

        // Traverse the prices starting from the second day.
        for (int i = 1; i < prices.size(); i++) {

            // If the current price is lower than the minimum price,
            // update the minimum buying price.
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }

            // Otherwise, calculate the profit
            // if we sell on the current day.
            else {

                // Current profit = Selling Price - Buying Price
                int profit = prices[i] - minPrice;

                // Update the maximum profit if current profit is larger.
                if (profit > maxProfit) {
                    maxProfit = profit;
                }
            }
        }

        // Return the maximum profit.
        // If no profit is possible, it remains 0.
        return maxProfit;
    }
};