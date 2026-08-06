class Solution {
public:
    int f(vector<int>& prices, int& n) {
        vector<vector<int>> dp(n+2, vector<int>(2, 0));


        for (int i = n-1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy)
                    dp[i][buy] = max(
                        dp[i+1][1],
                        -prices[i] + dp[i+1][0]
                    );
                else
                    dp[i][buy] = max(
                        dp[i+1][0],
                        prices[i] + dp[i+2][1]
                    );
            }
        }

        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return f(prices, n);
    }
};