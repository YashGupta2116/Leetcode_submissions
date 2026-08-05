class Solution {
public:
    int f(vector<int>& prices, int i, int sold, bool buy, vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || sold == 2) return 0;
        
        if (dp[i][buy][sold] != -1) return dp[i][buy][sold]; 

        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + f(prices, i+1, sold, false, dp), f(prices, i+1, sold, true, dp));
        } else {
            profit = max(prices[i] + f(prices, i+1, sold+1, true, dp), f(prices, i+1, sold, false, dp));
        }
    
        return dp[i][buy][sold] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return f(prices, 0, 0,true, dp);
    }
};