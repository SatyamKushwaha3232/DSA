class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // Poore grid ko pehle obstacles '#' se initialize karein
        vector<string> grid(m, string(n, '#'));
        
        // Pehli row (row 0) ko free cells '.' se bharlein
        for (int j = 0; j < n; ++j) {
            grid[0][j] = '.';
        }
        
        // Aakhri column (column n - 1) ko free cells '.' se bharlein
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }
        
        return grid;
    }
};