➡️ problemLinks --> https : // www.geeksforgeeks.org/problems/maximum-sub-array5443/1 ;

🚀Condition --> Single Transaction (Buy once, Sell once) selling on day 1 is not allowed because you must buy before you sell...

✅ mostOptimal --> class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // Initialize the minimum price with the first day's price
        int mini = prices[0];

        // Initialize maximum profit to 0 (we may not make any profit at all)
        int mxProfit = 0;

        // Start from the second day since we can't sell on the first day
        for (int i = 1; i < prices.size(); i++)
        {

            // Calculate the profit if we buy at 'mini' and sell today
            int cost = prices[i] - mini;

            // Update max profit if today's profit is higher
            mxProfit = max(mxProfit, cost);

            // Update the minimum price so far (best day to buy)
            mini = min(mini, prices[i]);
        }

        // Return the maximum profit we can achieve
        return mxProfit;
    }
};
// Time Complexity: O(n) - We traverse the prices array once.
// Space Complexity: O(1) - We use a constant amount of space for variables.