class Solution {
public:
    int f(string& s, int i, vector<int>& dp) {
        if (i == s.length()) return 1;
        if (s[i] == '0') return 0;

        if (dp[i] != -1) return dp[i];

        int ways = f(s, i+1, dp);

        if (i +1 < s.length()) {
            int num = (s[i] - '0') * 10 + (s[i+1] - '0');
            if (num >= 10 && num <= 26) {
                ways += f(s, i + 2, dp);
            }
        }

        return dp[i] = ways;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return f(s, 0, dp);
    }
};