class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) {
            if (k >= 0) return 0;
            return -1;
        }

        vector<int> arr(n);
        arr[n - 1] = nums[n - 1];
        for (int i = n-2; i >= 0; i--) {
            arr[i] = min(nums[i], arr[i+1]);
        }

        int maxSoFar = nums[0];
        for (int i = 0; i < n; i++) {
            maxSoFar = max(maxSoFar, nums[i]);
            if (maxSoFar - arr[i] <= k) return i;
        }

        return -1;
    }
};