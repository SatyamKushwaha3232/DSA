class Solution {
public:
    bool dfs(int i, int j, int balance,
             vector<vector<char>>& grid,
             vector<vector<vector<int>>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        // Current balance can never be negative
        if (balance < 0)
            return false;

        // Process current cell
        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        // Invalid
        if (balance < 0)
            return false;

        // Number of cells left AFTER current cell
        int remaining = (m - 1 - i) + (n - 1 - j);

        // Even if every remaining cell is ')',
        // balance must be closable
        if (balance > remaining)
            return false;

        // Destination
        if (i == m - 1 && j == n - 1)
            return balance == 0;

        // Memoization
        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool ans = false;

        // Move down
        if (i + 1 < m) {
            ans = dfs(i + 1, j, balance, grid, dp);
        }

        // Move right
        if (!ans && j + 1 < n) {
            ans = dfs(i, j + 1, balance, grid, dp);
        }

        return dp[i][j][balance] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Valid parentheses string must have even length
        if ((m + n - 1) % 2 != 0)
            return false;

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m + n + 1, -1)
            )
        );

        return dfs(0, 0, 0, grid, dp);
    }
};