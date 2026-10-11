
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        long long k = 1LL * k1 + k2;
        vector<int> diff(nums1.size());

        int maxDiff = 0;
        long long total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            total += diff[i];
        }

        // Enough operations to make all differences zero
        if (k >= total) return 0;

        // Binary search for the smallest feasible threshold
        int lo = 0, hi = maxDiff;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid) {
                    need += d - mid;
                }
            }

            if (need <= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        int x = lo;
        long long used = 0;
        long long ans = 0;

        for (int d : diff) {
            if (d > x) {
                used += d - x;
                d = x;
            }
            ans += 1LL * d * d;
        }

        // Use remaining operations to reduce x to x - 1
        long long remaining = k - used;
        ans -= remaining * (2LL * x - 1);

        return ans;
    }
};
