class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int nested = 0;
        for (char& c: s) {
            if (c == '(') {
                nested++;
            }
            if (c == ')') {
                nested--;
            }
            res = max(res, nested);
        }

        return res;
    }
};