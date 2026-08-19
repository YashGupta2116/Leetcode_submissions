class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefixMap;
        prefixMap[0] = 1;
        int res = 0;
        int currSum = 0;
        for (int i = 0; i < n; i++) {
            currSum += nums[i];
            if (prefixMap.contains(currSum - k)) {
                res += prefixMap[currSum - k];
            }
            prefixMap[currSum]++;
        }

        return res;
    }
};