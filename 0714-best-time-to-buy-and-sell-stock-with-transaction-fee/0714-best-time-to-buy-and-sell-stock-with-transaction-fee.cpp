class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& prices, int i, int buy, int fee) {

        if (i == prices.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        if (buy) {
            return dp[i][buy] = max(solve(prices, i + 1, 1, fee),
                                    -prices[i] + solve(prices, i + 1, 0, fee));
        } else {
            return dp[i][buy] =
                       max(solve(prices, i + 1, 0, fee),
                           prices[i] - fee + solve(prices, i + 1, 1, fee));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        dp.assign(n, vector<int>(2, -1));

        return solve(prices, 0, 1, fee);
    }
};