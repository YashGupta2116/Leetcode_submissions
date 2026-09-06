class Solution {
public:
      double f(string& s, string& t, int n, int m) {
        vector<double> prev(m+1, 0);
        vector<double> curr(m+1, 0);

        prev[0] = 1;
        curr[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == t[j-1]) {
                    curr[j] = prev[j-1] + prev[j];
                } else curr[j] = prev[j];
            }
            prev = curr;
        }


        return prev[m];
    }

    int numDistinct(string s, string t) {
        if (s.size() < t.size()) return 0;
        return (int)(f(s, t, s.size(), t.size()));
    }
};