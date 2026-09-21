class Solution {
public:
    bool f(string& s, vector<string>& wordDict, int i, vector<int>& dp) {
        if (i == s.size()) return true;

        if (dp[i] != -1) return dp[i];

        for (int j = 0; j < wordDict.size(); j++) {
            if (s.substr(i, wordDict[j].size()) == wordDict[j]) {
                if (f(s, wordDict, i+ wordDict[j].size(), dp)) {
                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return f(s, wordDict, 0, dp);
    }
};