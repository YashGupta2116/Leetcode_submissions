class Solution {
public:
    int f(vector<int>& cuts, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int res = INT_MAX;
        for (int k = i; k <= j; k++) {
            int cost = cuts[j+1] - cuts[i-1] + f(cuts, i, k-1, dp) + f(cuts, k+1, j, dp);
            res = min(res, cost);
        }

        return dp[i][j] = res;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));
        return f(cuts, 1, cuts.size() - 2, dp);
    }
};