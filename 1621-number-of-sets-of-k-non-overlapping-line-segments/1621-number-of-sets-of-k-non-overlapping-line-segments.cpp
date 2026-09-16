class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;

        long long ans = 1;

        for (int i = 1; i <= 2 * k; i++) {
            ans = ans * (n + k - i) % MOD;

            // Modular inverse of i
            long long base = i;
            long long exp = MOD - 2;
            long long inv = 1;

            while (exp > 0) {
                if (exp & 1)
                    inv = inv * base % MOD;

                base = base * base % MOD;
                exp >>= 1;
            }

            ans = ans * inv % MOD;
        }

        return ans;
    }
};