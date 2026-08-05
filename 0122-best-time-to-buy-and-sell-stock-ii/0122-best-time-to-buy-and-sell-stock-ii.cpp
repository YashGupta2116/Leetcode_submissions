class Solution {
public:
    int f(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2, 0), curr(2, 0);

        for (int i = n-1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[i] + prev[0], prev[1]);
                } else {
                    profit = max(prices[i] + prev[1], prev[0]);
                }

                curr[buy] = profit; 
            }
            prev = curr;
        }
        
        return prev[1];
    }   

    int maxProfit(vector<int>& prices) {
        return f(prices);
    }
};