class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mx = INT_MIN;
        int mn = INT_MAX;

        for (int num : nums) {
            mx = max(mx, num);
            mn = min(mn, num);
        }

        long long diff = (long long)mx - mn;
        return diff * 1LL * k;
    }
};