class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n= nums.size();
        if (n == 1) return 0;
        set<int> sorted;

        for (int i = 0; i < n; i++) {
            sorted.insert(nums[i]);
        }
        int res = 0;

        int prev = *sorted.begin(); 

        for (auto it = next(sorted.begin()); it != sorted.end(); ++it) {
            res = max(res, *it - prev);
            prev = *it;
        }

        return res;
    }
};