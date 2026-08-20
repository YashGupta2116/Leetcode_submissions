class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        for (const auto& it: mpp) {
            if (it.second > n/3) {
                res.push_back(it.first);
            }
        }

        return res;
    }
};