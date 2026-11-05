
class Solution {
public:
    using ll = long long;

    class Fenwick {
    public:
        int n;
        vector<ll> bit;

        Fenwick(int n) {
            this->n = n;
            bit.assign(n + 1, 0);
        }

        void update(int i, ll val) {
            for (; i <= n; i += i & -i)
                bit[i] += val;
        }

        ll query(int i) {
            ll sum = 0;

            for (; i > 0; i -= i & -i)
                sum += bit[i];

            return sum;
        }

        int kth(ll k) {
            int idx = 0;

            for (int step = 1 << 17; step; step >>= 1) {
                int next = idx + step;

                if (next <= n && bit[next] < k) {
                    idx = next;
                    k -= bit[next];
                }
            }

            return idx + 1;
        }
    };

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<int> vals = nums;
        sort(vals.begin(), vals.end());

        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();

        Fenwick freq(m), sum(m);

        auto add = [&](int v, int delta) {
            int id = lower_bound(vals.begin(), vals.end(), v)
                     - vals.begin() + 1;

            freq.update(id, delta);
            sum.update(id, 1LL * v * delta);
        };

        vector<ll> cost(n - x + 1);

        // First window
        for (int i = 0; i < x; i++)
            add(nums[i], 1);

        auto getCost = [&]() -> ll {
            int midId = freq.kth((x + 1) / 2);
            ll median = vals[midId - 1];

            ll leftCount = freq.query(midId - 1);
            ll leftSum = sum.query(midId - 1);

            ll totalCount = freq.query(m);
            ll totalSum = sum.query(m);

            ll rightCount = totalCount - leftCount - 1;
            ll rightSum = totalSum - leftSum - median;

            return median * leftCount - leftSum
                 + rightSum - median * rightCount;
        };

        for (int i = 0; i <= n - x; i++) {
            cost[i] = getCost();

            if (i < n - x) {
                add(nums[i], -1);
                add(nums[i + x], 1);
            }
        }

        // DP with rolling arrays
        const ll INF = 1e18;

        vector<ll> prev(n + 1, 0), curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];

                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
