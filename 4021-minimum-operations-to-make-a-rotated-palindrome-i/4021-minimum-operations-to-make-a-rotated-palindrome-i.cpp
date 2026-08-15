class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            nums[i] = s[i] - 'a';
        }

        int best = INT_MAX;

        for (int r = 0; r < n; r++) {
            int cost = r;

            for (int i = 0; i < n/2; i++) {
                int a = nums[(i + r) % n];
                int b = nums[(n-1-i+r) % n];
                int d = abs(a-b);
                cost += min(d, 26-d);
            }
            best = min(best, cost);
        }

        return best;
    }
};