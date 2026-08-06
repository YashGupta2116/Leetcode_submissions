class Solution {
public:
    int f(vector<int>& prices, int& n, int& fee) {
        vector<int> after(2, 0);
        vector<int> curr(2, 0);

        for (int i = n-1; i >= 0; i--) {
            curr[1] = max(after[1], -prices[i] + after[0]);
            curr[0] = max(after[0], prices[i] - fee + after[1]);

            after = curr;
        }

        return after[1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        return f(prices, n, fee);
    }
};