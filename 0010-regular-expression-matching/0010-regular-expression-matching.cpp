class Solution {
public:
    bool f(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if (j == p.size()) {
            return i == s.size();
        }

        if (dp[i][j] != -1) return dp[i][j];

        bool firstMatch = 
            i < s.size() &&
            (s[i] == p[j] || p[j] == '.');

        
        if (j + 1 < p.size() && p[j + 1] == '*') {
            return dp[i][j] = 
                f(s, p, i, j + 2, dp) ||
                (firstMatch && f(s, p, i + 1, j, dp));
        }

        if (firstMatch) {
            return dp[i][j] = f(s, p, i + 1, j + 1, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1 , -1));
        return f(s, p, 0, 0, dp);
    }
};