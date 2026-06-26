class Solution {
public:
    using ll = long long;

    struct BIT {
        int n;
        vector<int> bit;

        BIT(int size) {
            n = size;
            bit.assign(n + 1, 0);
        }

        void update(int idx) {
            while (idx <= n) {
                bit[idx]++;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        BIT bit(vals.size());
        long long ans = 0;

        for (int x : pref) {
            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;

            ans += bit.query(idx - 1);
            bit.update(idx);
        }

        return ans;
    }
};