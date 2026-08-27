class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long res = 0;
        int n = columnTitle.length();
        for (int i = 0; i < n; i++) {
            res += pow(26, n - i - 1) * (columnTitle[i] - 'A' + 1);
        }

        return (int)res;
    }
};