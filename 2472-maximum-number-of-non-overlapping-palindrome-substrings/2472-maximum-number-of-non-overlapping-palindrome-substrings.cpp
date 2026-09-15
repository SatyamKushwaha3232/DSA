class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[i][j] = whether s[i...j] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome DP
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j] &&
                    (len <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = maximum palindromes in s[0...i-1]
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            // Don't choose a palindrome ending at i-1
            dp[i] = dp[i - 1];

            // Try every palindrome ending at i-1
            for (int j = 0; j < i; j++) {
                int len = i - j;

                if (len >= k && pal[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};