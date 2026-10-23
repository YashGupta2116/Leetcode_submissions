class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.size()-1, j = num2.size()-1;
        int carry = 0;
        while (i >= 0 && j >= 0) {
            int digit = ((num1[i] - '0') + (num2[j] - '0')) + carry;
            carry = digit / 10;

            res += char(digit % 10 + '0');
            i--; j--;
        }

        while (i >= 0) {
            int digit = (num1[i] - '0' + carry);
            carry = digit / 10;

            res += char(digit % 10 + '0');
            i--;
        }

        while (j >= 0) {
            int digit = (num2[j] - '0' + carry);
            carry = digit / 10;

            res += char(digit % 10 + '0');
            j--;
        }

        if (carry) res += char(carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};