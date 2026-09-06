class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Empty t can always be formed in exactly 1 way
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // Skip s[i-1]
                dp[i][j] = dp[i - 1][j];

                // Use s[i-1] if characters match
                if (s[i - 1] == t[j - 1]) {
                    if (dp[i - 1][j - 1] <= INT_MAX - dp[i - 1][j]) {
                        dp[i][j] += dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = INT_MAX;
                    }
                }
            }
        }

        return dp[n][m];
    }
};