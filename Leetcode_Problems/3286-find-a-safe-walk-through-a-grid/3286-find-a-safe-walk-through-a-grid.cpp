class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));

        queue<pair<pair<int,int>, int>> q;

        int startHealth = health - grid[0][0];

        if (startHealth <= 0) return false;

        q.push({{0,0}, startHealth});
        best[0][0] = startHealth;

        int dirs[5] = {0,1,0,-1,0};

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int r = curr.first.first;
            int c = curr.first.second;
            int h = curr.second;

            if (r == m - 1 && c == n - 1)
                return true;

            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d];
                int nc = c + dirs[d + 1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {

                    int nh = h - grid[nr][nc];

                    if (nh > 0 && nh > best[nr][nc]) {
                        best[nr][nc] = nh;
                        q.push({{nr, nc}, nh});
                    }
                }
            }
        }

        return false;
    }
};