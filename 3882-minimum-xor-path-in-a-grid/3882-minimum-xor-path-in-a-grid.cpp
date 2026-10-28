class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MAX_XOR = 2048; // Max grid value is 1023, so max XOR value < 2048
        
        // dp[j] stores a bitset of possible XOR values reachable at column j
        vector<bitset<MAX_XOR>> dp(n);
        
        // Initialize the top-left cell
        dp[0].set(grid[0][0]);
        
        // Fill out the first row (can only move right)
        for (int j = 1; j < n; ++j) {
            int val = grid[0][j];
            for (int v = 0; v < MAX_XOR; ++v) {
                if (dp[j - 1].test(v)) {
                    dp[j].set(v ^ val);
                }
            }
        }
        
        // Process the remaining rows
        for (int i = 1; i < m; ++i) {
            vector<bitset<MAX_XOR>> next_dp(n);
            
            // First column of the current row (can only move down from above)
            int val0 = grid[i][0];
            for (int v = 0; v < MAX_XOR; ++v) {
                if (dp[0].test(v)) {
                    next_dp[0].set(v ^ val0);
                }
            }
            
            // Remaining columns (can move down from above OR right from the left column)
            for (int j = 1; j < n; ++j) {
                int val = grid[i][j];
                
                // Check values coming from the top cell (dp[j])
                for (int v = 0; v < MAX_XOR; ++v) {
                    if (dp[j].test(v)) {
                        next_dp[j].set(v ^ val);
                    }
                }
                
                // Check values coming from the left cell (next_dp[j-1])
                for (int v = 0; v < MAX_XOR; ++v) {
                    if (next_dp[j - 1].test(v)) {
                        next_dp[j].set(v ^ val);
                    }
                }
            }
            // Move onto the next row
            dp = move(next_dp);
        }
        
        // The answer is the lowest set bit in the bottom-right cell's bitset
        for (int v = 0; v < MAX_XOR; ++v) {
            if (dp[n - 1].test(v)) {
                return v;
            }
        }
        
        return 0;
    }
};