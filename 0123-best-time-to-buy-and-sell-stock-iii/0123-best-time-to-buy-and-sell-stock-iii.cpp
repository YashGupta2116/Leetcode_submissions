class Solution {
public:
    int f(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for (int i = n-1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int sold = 1; sold >= 0; sold--) {
                    if (buy) {
                        dp[i][buy][sold] = max(
                            -prices[i] + dp[i + 1][false][sold],
                            dp[i + 1][true][sold]
                        );
                    } else {
                        dp[i][buy][sold] = max(
                            prices[i] + dp[i + 1][true][sold + 1],
                            dp[i + 1][false][sold]
                        );
                    }
                }
            }
        }

        return dp[0][1][0];
    }

    int maxProfit(vector<int>& prices) {
        return f(prices);
    }
};