class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 10 && nums[i] == i) return i;
            if (nums[i] >= 10) {
                string num = to_string(nums[i]);
                int res = 0;
                for (char& digit: num) {
                    res = res + (digit - '0');
                }

                if (res == i) {
                    return i;
                }
            }
        }

        return -1;
    }
};