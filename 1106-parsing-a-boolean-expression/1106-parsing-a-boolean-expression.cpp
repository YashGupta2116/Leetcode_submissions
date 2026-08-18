class Solution {
public:
    bool eval(vector<char>& ch, char operation) {
        if (operation == '|') {
            for (char c : ch) {
                if (c == 't') return true;
            }
            return false;
        }

        if (operation == '&') {
            for (char c : ch) {
                if (c == 'f') return false;
            }
            return true;
        }

        return ch[0] == 'f';
    }

    bool parseBoolExpr(string expression) {
        stack<char> stk;
        int n = expression.length();

        for (int i = 0; i < n; i++) {
            if (expression[i] == ',') continue;

            if (expression[i] == ')') {
                vector<char> ch;
                while (!stk.empty() && stk.top() != '(') {
                    ch.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
                char operation = stk.top();
                stk.pop();

                bool result = eval(ch, operation);
                stk.push(result ? 't' : 'f');
            } else {
                stk.push(expression[i]);
            }
        }

        return stk.top() == 't';
    }
};