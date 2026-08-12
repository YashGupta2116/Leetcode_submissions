class Solution {
public:
    int f(vector<int>& piles, int i, int M, vector<vector<int>>& dp) {
        int n = piles.size();
        if (i >= n) return 0;

        if (dp[i][M] != -1) return dp[i][M];

        int remaining = 0;
        for (int j = i; j < n; j++) {
            remaining += piles[j];
        }

        int res = 0;
        for (int k = 1; k <= 2 * M && i + k <= n; k++) {
            int opponent = f(piles, i + k, max(M, k), dp);

            res = max(res,remaining - opponent);
        }

        return dp[i][M] = res;
    }

    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size()+1, -1));
        return f(piles, 0, 1, dp);
    }
};