class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;
        cout << 'z' - 'b' << endl; 
        for (int i = 0; i < s.size(); i++) {
            res += (26 - (s[i] - 'a')) * (i+1);
        }

        return res;
    }
};