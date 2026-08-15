class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n , 0));

        for (int i = nums.size()-2; i >= 1; i--) {
            for (int j = i; j <= n-2; j++) {
                int res = INT_MIN;
                for (int k = i; k <= j; k++) {
                    int coins = nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    res = max(res, coins);
                }
                dp[i][j] = res;
            }
        }

        return dp[1][n-2];
    }
};