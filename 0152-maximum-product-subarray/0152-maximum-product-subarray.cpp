class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maxi = nums[0];
        long long mini = nums[0];
        long long ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            long long x = nums[i];

            if (x < 0)
                swap(maxi, mini);

            maxi = max(x, maxi * x);
            mini = min(x, mini * x);

            ans = max(ans, maxi);
        }

        return ans;
    }
};