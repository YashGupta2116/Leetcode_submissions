class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> res;
    
        for (int num: nums) {
            string s = "";
            int power = 0;

            while (num > 0) {
                if (num & 1) {
                    if (power <= 25) {
                        s += char('a' + power);
                    } else {
                        s += string(1 << (power - 25), 'z');
                    }
                }

                num >>= 1;
                power++;
            }

            reverse(s.begin(), s.end());
            res.push_back(s);
        }

        return res;
    }
};