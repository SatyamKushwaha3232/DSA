class Solution {
public:
    using ll = long long;

    ll gcd(ll a, ll b) {
        while (b) {
            ll t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    ll lcm(ll a, ll b) {
        return a / gcd(a, b) * b;
    }

    // Count how many distinct amounts <= x
    // can be formed using at least one denomination.
    ll countAmounts(ll x, vector<int>& coins) {
        int m = coins.size();
        ll count = 0;

        // Inclusion-Exclusion
        for (int mask = 1; mask < (1 << m); mask++) {
            ll L = 1;
            bool valid = true;
            int bits = 0;

            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    L = lcm(L, coins[i]);

                    if (L > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) continue;

            ll ways = x / L;

            if (bits & 1)
                count += ways;
            else
                count -= ways;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        ll low = 1;
        ll high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            ll mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};