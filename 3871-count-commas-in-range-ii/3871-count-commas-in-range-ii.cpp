class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) return 0;
        long long copyN = n;
        int commas = 0;
        long long res = 0;
        while (copyN >= 1000) {
            copyN /= 1000;
            commas++;
        }

        while (commas) {
            long long num = round(pow(1000, commas));
            res += n - num + 1;
            commas--;
        }

        return res;
    }
};