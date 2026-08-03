class Solution {
public:
    bool f(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 && j < 0) return true;
        if (j < 0) return false;
        if (i < 0) {
            while (j >= 0) {
                if (p[j] != '*') return false;
                j--;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];


        if (s[i] == p[j] || p[j] == '?') 
            return dp[i][j] = f(s, p, i-1, j-1, dp);
        if (p[j] == '*')
            return dp[i][j] = (f(s, p, i, j-1, dp) || f(s, p, i-1, j, dp));

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return f(s, p, s.size()-1, p.size()-1, dp);
    }
};