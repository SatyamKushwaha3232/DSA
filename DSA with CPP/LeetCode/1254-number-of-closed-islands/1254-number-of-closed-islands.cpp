#include <vector>

using namespace std;

class Solution {
private:
    int rows;
    int cols;

    void dfs(int r, int c, vector<vector<int>>& grid) {
        // Base case: if out of bounds or already water/visited, stop
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 0) {
            return;
        }

        // Mark the current land cell as visited by converting it to water
        grid[r][c] = 1;

        // Flood fill in all 4 directions
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        // Step 1: Eliminate all open islands connected to the boundary
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // Check if it's a boundary cell and contains land (0)
                if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) && grid[r][c] == 0) {
                    dfs(r, c, grid);
                }
            }
        }
        
        // Step 2: Count the remaining closed islands in the interior
        int closed_island_count = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    closed_island_count++;
                    dfs(r, c, grid); // Sink this entire closed island
                }
            }
        }
        
        return closed_island_count;
    }
};
