class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0;
        int n = words.size();

        while (i < n) {
            int start = i;
            int letters = 0;

            while (i < n) {
                int spacesNeeded = i - start;
                if (letters + spacesNeeded + words[i].length() > maxWidth) {
                    break;
                }

                letters += words[i].size();
                i++;
            }

            int end = i - 1;
            int numWords = end - start + 1;
            int gaps = numWords - 1;

            string line;

            if (i == n || gaps == 0) {
                for (int j = start; j <= end; j++) {
                    if (j > start) {
                        line += ' ';
                    }

                    line += words[j];
                }

                line.append(maxWidth - line.size(), ' ');
            } else {
                int totalSpaces = maxWidth - letters;
                int spacesPerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int j = start; j < end; j++) {
                    line += words[j];
                    int spaces = spacesPerGap;

                    if (j - start < extraSpaces) {
                        spaces++;
                    }

                    line.append(spaces, ' ');
                }
                line += words[end];
            }
            res.push_back(line);
        }

        return res;
    }
};