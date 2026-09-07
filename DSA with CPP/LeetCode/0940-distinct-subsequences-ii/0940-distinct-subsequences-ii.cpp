class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        long long dp = 1;  // empty subsequence

        vector<long long> last(26, 0);

        for (char c : s) {
            int idx = c - 'a';

            long long newDp =
                (2 * dp % MOD - last[idx] + MOD) % MOD;

            last[idx] = dp;
            dp = newDp;
        }

        // Remove empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};