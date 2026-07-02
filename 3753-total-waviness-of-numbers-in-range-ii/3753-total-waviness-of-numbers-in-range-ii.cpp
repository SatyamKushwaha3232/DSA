class Solution {
public:
    using ll = long long;

    string s;
    bool vis[20][2][11][11];
    pair<ll, ll> dp[20][2][11][11];

    pair<ll, ll> solve(int pos, bool started, int prev2, int prev1, bool tight) {
        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][started][prev2][prev1]) {
            return dp[pos][started][prev2][prev1];
        }

        int limit = tight ? s[pos] - '0' : 9;

        ll totalCount = 0;
        ll totalWave = 0;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);

            if (!started && d == 0) {
                auto res = solve(pos + 1, false, 10, 10, newTight);
                totalCount += res.first;
                totalWave += res.second;
            } 
            else {
                int add = 0;

                if (started && prev2 != 10) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d)) {
                        add = 1;
                    }
                }

                int newPrev2, newPrev1;

                if (!started) {
                    newPrev2 = 10;
                    newPrev1 = d;
                } else {
                    newPrev2 = prev1;
                    newPrev1 = d;
                }

                auto res = solve(pos + 1, true, newPrev2, newPrev1, newTight);

                totalCount += res.first;
                totalWave += res.second + res.first * add;
            }
        }

        if (!tight) {
            vis[pos][started][prev2][prev1] = true;
            dp[pos][started][prev2][prev1] = {totalCount, totalWave};
        }

        return {totalCount, totalWave};
    }

    ll calc(ll n) {
        if (n <= 0) return 0;

        s = to_string(n);
        memset(vis, false, sizeof(vis));

        return solve(0, false, 10, 10, true).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};