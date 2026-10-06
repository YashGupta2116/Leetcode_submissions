class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0, answer = 0;

        for (char& c: s) {
            if (c == '(') {
                balance++;
            } else {
                if (balance > 0) {
                    balance--;
                } else {
                    answer++;
                }
            }
        }

        return balance + answer;
    }
};