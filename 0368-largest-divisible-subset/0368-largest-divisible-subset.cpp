class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1), hash(n);

        int lastIdx = 0;
        for (int i = 0; i < n; i++) {
            hash[i] = i;

            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if (dp[i] > dp[lastIdx]) lastIdx = i;
        }

        vector<int> res;

        while (true) {
            res.push_back(nums[lastIdx]);

            if (hash[lastIdx] == lastIdx)
                break;

            lastIdx = hash[lastIdx];
        }

        reverse(res.begin(), res.end());

        return res;
    }
};