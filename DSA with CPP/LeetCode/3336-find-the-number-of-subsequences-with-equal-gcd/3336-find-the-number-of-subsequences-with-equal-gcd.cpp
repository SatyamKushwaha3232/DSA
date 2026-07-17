class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        const int M = 200;

        vector<vector<int>> dp(M + 1, vector<int>(M + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            auto ndp = dp;

            for (int g1 = 0; g1 <= M; g1++) {
                for (int g2 = 0; g2 <= M; g2++) {
                    if (!dp[g1][g2]) continue;

                    int ng1 = (g1 == 0 ? x : gcd(g1, x));
                    ndp[ng1][g2] += dp[g1][g2];
                    if (ndp[ng1][g2] >= MOD)
                        ndp[ng1][g2] -= MOD;

                    int ng2 = (g2 == 0 ? x : gcd(g2, x));
                    ndp[g1][ng2] += dp[g1][g2];
                    if (ndp[g1][ng2] >= MOD)
                        ndp[g1][ng2] -= MOD;
                }
            }

            dp.swap(ndp);
        }

        long long ans = 0;

        for (int g = 1; g <= M; g++) {
            ans += dp[g][g];
            ans %= MOD;
        }

        return (int)ans;
    }
};