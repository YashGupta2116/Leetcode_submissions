class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int minimum = prices[0];    
        for (int i = 1; i<n; i++) {
            int sell = prices[i];
            profit = max(profit, sell - minimum);
            minimum = min(sell , minimum);
        }
        return profit;
    }
};