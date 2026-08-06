class Solution {
public:
    int f(vector<int>& prices, int& n, int& fee) {
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for (int i = n-1; i >= 0; i--) {
            dp[i][1] = max(dp[i+1][1], -prices[i] + dp[i+1][0]);
            dp[i][0] = max(dp[i+1][0], prices[i] - fee + dp[i+1][1]);
        }

        return dp[0][1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        return f(prices, n, fee);
    }
};