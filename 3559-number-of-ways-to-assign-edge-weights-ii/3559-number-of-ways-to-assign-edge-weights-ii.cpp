class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<vector<int>> g;
    vector<vector<pair<int,int>>> qs;
    vector<int> parent, ancestor, depth, vis;
    vector<int> ans;
    vector<int> pow2;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        parent[find(b)] = find(a);
    }

    void dfs(int u, int p) {
        parent[u] = u;
        ancestor[u] = u;
        vis[u] = 1;

        for (int v : g[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u);

            unite(u, v);
            ancestor[find(u)] = u;
        }

        for (auto &[v, idx] : qs[u]) {
            if (vis[v]) {
                int lca = ancestor[find(v)];
                int len = depth[u] + depth[v] - 2 * depth[lca];

                ans[idx] = (len == 0 ? 0 : pow2[len - 1]);
            }
        }
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        int q = queries.size();

        g.assign(n + 1, {});
        qs.assign(n + 1, {});
        parent.assign(n + 1, 0);
        ancestor.assign(n + 1, 0);
        depth.assign(n + 1, 0);
        vis.assign(n + 1, 0);
        ans.assign(q, 0);
        pow2.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow2[i] = (1LL * pow2[i - 1] * 2) % MOD;
        }

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            qs[u].push_back({v, i});
            qs[v].push_back({u, i});
        }

        dfs(1, 0);

        return ans;
    }
};