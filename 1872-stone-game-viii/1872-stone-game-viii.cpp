class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Prefix sum
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // dp = best score difference starting from this prefix
        int dp = stones[n - 1];

        // i must be at least 1 because x > 1
        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, stones[i] - dp);
        }

        return dp;
    }
};