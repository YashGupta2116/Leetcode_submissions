class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int expectedSum = ((n*n) * ((n*n) + 1)) / 2 ;
        int totalSum = 0;
        unordered_set<int> seen;
        int duplicate = 0;
        for (const auto& numbers: grid) {
            for (auto& it: numbers) {
                if (seen.contains(it)) {
                    duplicate = it;
                }
                seen.insert(it);
                totalSum += it;
            }
        }

        totalSum -= duplicate;

        return {duplicate, expectedSum - totalSum};
    }
};