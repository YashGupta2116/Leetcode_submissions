class Solution {
public:
    int f(vector<int>& prices, int& k) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int sold = 1; sold <= k; sold++) {
                    if (buy == 0) {
                        curr[buy][sold] = max(0 + after[0][sold],
                                            -prices[i] + after[1][sold]);
                    }

                    if (buy == 1) {
                        curr[buy][sold] = max(0 + after[1][sold],
                                            prices[i] + after[0][sold - 1]);
                    }
                }
            }
            after = curr;
        }

        return after[0][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        return f(prices, k);
    }
};