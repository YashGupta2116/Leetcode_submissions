class Solution {
public:
    string getHint(string secret, string guess) {
        int i = 0, j = 0;
        int n = secret.length();
        string res = "";
        int bulls = 0;
        int cows = 0;
        unordered_map<char, int> freqSecret;
        unordered_map<char, int> freqGuess;
        for (int i = 0; i < n; i++) {
            freqSecret[secret[i]]++; 
            freqGuess[guess[i]]++; 
            if (secret[i] == guess[i]) {
                bulls++;
                freqSecret[secret[i]]--;
                freqGuess[guess[i]]--;
            }
        }

        for (auto& it: freqSecret) {
            if (freqGuess[it.first] != 0) {
                cows += min(freqSecret[it.first], freqGuess[it.first]);
            }
        }

        res = res + to_string(bulls);
        res = res + 'A';
        res = res + to_string(cows);
        res = res + 'B';


        return res;
    }
};