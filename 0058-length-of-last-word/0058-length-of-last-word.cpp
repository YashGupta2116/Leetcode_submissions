class Solution {
public:
    std::string trim(const std::string& str) {
        const std::string whitespace = " \t\n\r\f\v";
        
        size_t start = str.find_first_not_of(whitespace);
        if (start == std::string::npos) return "";

        size_t end = str.find_last_not_of(whitespace);

        return str.substr(start, end - start + 1);
    }

    int lengthOfLastWord(string s) {
        s = trim(s);
        int i = s.length()-1;
        int res = 0;
        while (i >= 0 && s[i] != ' ') {
            res++;
            i--;
        }

        return res;
    }
};