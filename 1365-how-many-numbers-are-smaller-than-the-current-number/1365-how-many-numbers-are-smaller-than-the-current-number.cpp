class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        map<int, int> mpp;

        for (int i = 0; i < sorted.size(); i++) {
            if (!mpp.count(sorted[i])) {
                mpp[sorted[i]] = i;
            }
        }

        vector<int> res;

        for (int num : nums) {
            res.push_back(mpp[num]);
        }

        return res;
    }
};