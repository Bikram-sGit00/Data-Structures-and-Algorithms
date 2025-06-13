➡️ problemLinks --> https : // www.geeksforgeeks.org/problems/maximum-sub-array5443/1 ;

🚀Condition --> Unlimited Transactions(Buy / Sell as many times as profitable)

✅ mostOptimal --> class Solution
{
public:
    int stockBuySell(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

// Time Complexity: O(n) - We traverse the prices array once.
// Space Complexity: O(1) - We use a constant amount of space for variables.