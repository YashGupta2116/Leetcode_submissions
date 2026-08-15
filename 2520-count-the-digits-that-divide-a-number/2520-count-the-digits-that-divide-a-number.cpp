class Solution {
public:
    int countDigits(int num) {
        string s = to_string(num);
        int res = 0;
        for (char& c: s) {
            if (num % (c-'0') == 0) res++;
        }

        return res;
    }
};