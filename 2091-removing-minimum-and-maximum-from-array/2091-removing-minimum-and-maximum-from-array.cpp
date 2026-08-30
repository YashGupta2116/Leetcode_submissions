class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        int posiMin = INT_MAX;
        int posiMax = INT_MAX;
        int n= nums.size();
        for (int i = 0; i < n; i++) {
            if (mini >= nums[i]) {
                mini = nums[i];
                posiMin = i;
            }
            if (maxi <= nums[i]) {
                maxi = nums[i];
                posiMax = i;
            }
        }

        int a = min(posiMin, posiMax);
        int b = max(posiMin, posiMax);

        int bothLeft = b + 1;
        int bothRight = n - a;
        int oneEach = (a + 1) + (n - b);

        return min({bothLeft, bothRight, oneEach});
    }
};