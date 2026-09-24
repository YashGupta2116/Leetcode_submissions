class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;
        int res = 0;

        for (int i = 1; i < n-1; i++) {
            if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
                int l = i-1, r = i+1;
                while (l >= 0 && arr[l] < arr[l+1]) {
                    l--;
                }

                while (r+1 < n && arr[r] > arr[r+1]) {
                    r++;
                }

                res = max(res, r - l);
            }
        }
        return res;
    }
};