class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dirs[5] = {0, 1, 0, -1, 0};

        // Step 1: nearest thief distance
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d];
                int nc = c + dirs[d + 1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Step 2: max-min path using priority queue
        priority_queue<vector<int>> pq;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        pq.push({dist[0][0], 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int safe = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (visited[r][c]) continue;
            visited[r][c] = 1;

            if (r == n - 1 && c == n - 1) {
                return safe;
            }

            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d];
                int nc = c + dirs[d + 1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    int newSafe = min(safe, dist[nr][nc]);
                    pq.push({newSafe, nr, nc});
                }
            }
        }

        return 0;
    }
};