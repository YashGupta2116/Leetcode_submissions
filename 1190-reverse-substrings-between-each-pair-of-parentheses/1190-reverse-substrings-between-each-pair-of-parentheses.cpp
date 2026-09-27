class Solution {
public:
    string reverseString(string& s, int& i) {
        string res = "";
        while (i < s.size()) {
            if (s[i] == '(') {
                i++;
                string inner = reverseString(s, i);
                res += inner;
            }
            else if (s[i] == ')') {
                i++;
                reverse(res.begin(), res.end());
                return res;
            }
            else {
                res += s[i];
                i++;
            }
        }   

        return res;
    }

    string reverseParentheses(string s) {
        int i = 0;
        return reverseString(s, i);
    }
};