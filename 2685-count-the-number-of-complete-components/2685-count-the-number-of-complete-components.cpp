class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis,
             int &nodes, int &edgeSum) {
        vis[node] = true;
        nodes++;
        edgeSum += adj[node].size();

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, vis, nodes, edgeSum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0;
                int edgeSum = 0;

                dfs(i, adj, vis, nodes, edgeSum);

                int actualEdges = edgeSum / 2;
                int requiredEdges = nodes * (nodes - 1) / 2;

                if (actualEdges == requiredEdges)
                    ans++;
            }
        }

        return ans;
    }
};