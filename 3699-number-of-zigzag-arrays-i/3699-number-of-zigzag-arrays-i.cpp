class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        vector<long long> up(m), down(m);

        // length = 2
        for (int i = 0; i < m; i++) {
            up[i] = i;              // previous value smaller
            down[i] = m - 1 - i;    // previous value greater
        }

        for (int len = 3; len <= n; len++) {
            vector<long long> newUp(m), newDown(m);

            long long prefix = 0;
            for (int i = 0; i < m; i++) {
                newUp[i] = prefix;
                prefix = (prefix + down[i]) % MOD;
            }

            long long suffix = 0;
            for (int i = m - 1; i >= 0; i--) {
                newDown[i] = suffix;
                suffix = (suffix + up[i]) % MOD;
            }

            up = newUp;
            down = newDown;
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return ans;
    }
};