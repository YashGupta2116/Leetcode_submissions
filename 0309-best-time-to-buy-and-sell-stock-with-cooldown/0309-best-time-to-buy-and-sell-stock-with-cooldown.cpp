class Solution {
public:
    int f(vector<int>& prices, int& n, int i, bool buy, bool cooldown, vector<vector<vector<int>>>& dp) {
        if (i >= n) return 0;

        if (dp[i][buy][cooldown] != -1) return dp[i][buy][cooldown];

        int profit = 0;
        if (buy) {
            profit = max(f(prices, n, i+1, buy, cooldown, dp), -prices[i] + f(prices, n, i+1, false, cooldown, dp));
        } else {
            profit = max(f(prices, n, i+1, buy, cooldown, dp), prices[i] + f(prices, n, i+2, true, true, dp));
        }

        return dp[i][buy][cooldown] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return f(prices, n, 0, true, false, dp);
    }
};