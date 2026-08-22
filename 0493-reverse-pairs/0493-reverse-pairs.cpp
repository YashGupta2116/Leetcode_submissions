class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid +1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) temp.push_back(nums[left++]);
            else temp.push_back(nums[right++]);
        }

        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        for (int i = low; i <= high; i++) nums[i] = temp[i-low];
    }

    void mergeSort(vector<int>& nums, int low, int high, int& res) {
        if (low >= high) return;

        int mid = low + (high - low)/2;

        mergeSort(nums, low, mid, res);
        mergeSort(nums, mid+1, high, res);

         int right = mid + 1;

        for (int left = low; left <= mid; left++) {
            while (right <= high &&
                   (long long)nums[left] > 2LL * nums[right]) {
                right++;
            }

            res += right - (mid + 1);
        }

        merge(nums, low, mid, high);
    }

    int reversePairs(vector<int>& nums) {
        int res = 0;
        mergeSort(nums, 0, nums.size()-1, res);

        return res;
    }
};