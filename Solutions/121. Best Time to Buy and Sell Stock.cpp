// Date Completed: 12/4/2024

// Leetcode Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];   // sets the current minimum price to buy the stock at day 0
        int maxProfit = 0;  // sets the current max profit to 0
        for (int i = 1; i < prices.size(); i++) {   // represents the selling day, and we started at day 0 to buy
            minPrice = min(minPrice, prices[i]);    // gets the new minimum price to buy, we do not have to worry about going backwards in time because our loop goes forward
                                                    // if day 1 is larger than day 0 than the buying day does not get updated
            maxProfit = max(maxProfit, prices[i] - minPrice);   // checks the current selling day - buying day price vs the current maxProfit

            // with this approach, we keep track of the minimum price and maximum profit
            // the minimum price is good because although there might not be a higher sell day in the future, we have kept track of our previous max profit and move forward in the days
            // ex: 3, 7, 1, 2
            // Buy 3 and Sell 7 is best, but the minPrice gets updated to 1
            // This is ok however because our max profit of 7 - 3 is still kept
        }
        return maxProfit; // returns maxProfit
    }
};