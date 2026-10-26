class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int island_count = 0;
        
        // Direction vectors for 4-directional traversal
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                // If a new land cell is detected
                if (grid[r][c] > 0) {
                    long long island_sum = grid[r][c];
                    grid[r][c] = 0; // Sink the cell to mark it as visited
                    
                    queue<pair<int, int>> q;
                    q.push({r, c});
                    
                    while (!q.empty()) {
                        auto [curr_r, curr_c] = q.front();
                        q.pop();
                        
                        for (int i = 0; i < 4; ++i) {
                            int nr = curr_r + dr[i];
                            int nc = curr_c + dc[i];
                            
                            // Validate grid boundaries and land visibility
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                                island_sum += grid[nr][nc];
                                grid[nr][nc] = 0; // Sink cell
                                q.push({nr, nc});
                            }
                        }
                    }
                    
                    // Increment count if the total sum of the island is divisible by k
                    if (island_sum % k == 0) {
                        island_count++;
                    }
                }
            }
        }
        
        return island_count;
    }
};