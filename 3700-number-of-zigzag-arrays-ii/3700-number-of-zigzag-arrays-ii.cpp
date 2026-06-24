class Solution {
public:
    static const int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix &A, Matrix &B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();
        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (exp > 0) {
            if (exp & 1) {
                res = multiply(res, base);
            }

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int states = 2 * m;

        vector<long long> dp(states, 0);

        // Length = 2 initial states
        for (int i = 0; i < m; i++) {
            dp[i] = i;                 // up
            dp[i + m] = m - 1 - i;     // down
        }

        if (n == 2) {
            long long ans = 0;
            for (long long x : dp) ans = (ans + x) % MOD;
            return ans;
        }

        Matrix T(states, vector<long long>(states, 0));

        // newUp[i] = sum oldDown[j], j < i
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                T[i][j + m] = 1;
            }
        }

        // newDown[i] = sum oldUp[j], j > i
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                T[i + m][j] = 1;
            }
        }

        Matrix P = power(T, n - 2);

        long long ans = 0;

        for (int i = 0; i < states; i++) {
            long long val = 0;

            for (int j = 0; j < states; j++) {
                val = (val + P[i][j] * dp[j]) % MOD;
            }

            ans = (ans + val) % MOD;
        }

        return ans;
    }
};