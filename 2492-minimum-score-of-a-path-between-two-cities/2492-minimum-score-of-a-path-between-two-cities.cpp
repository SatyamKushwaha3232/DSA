class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<int> vis(n + 1, 0);

        queue<int> q;
        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &[v, d] : adj[u]) {

                ans = min(ans, d);

                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};