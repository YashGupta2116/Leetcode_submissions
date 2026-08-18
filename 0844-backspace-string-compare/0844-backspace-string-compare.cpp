class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string newS = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                if (!newS.empty()) newS.pop_back();
            } else {
                newS.push_back(s[i]);
            }
        }

        string newT = "";
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == '#') {
                if (!newT.empty()) newT.pop_back();
            } else {
                newT.push_back(t[i]);
            }
        }

        return newS == newT;
    }
};