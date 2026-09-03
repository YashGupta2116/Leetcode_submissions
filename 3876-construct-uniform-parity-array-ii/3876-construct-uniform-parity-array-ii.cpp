class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int evens = 0;
        int smallest = INT_MAX;
        for (int& n: nums1) {
            if (n % 2 == 0) evens++;
            smallest = min(smallest, n);
        }

        return smallest % 2 || evens == nums1.size();
    }
};