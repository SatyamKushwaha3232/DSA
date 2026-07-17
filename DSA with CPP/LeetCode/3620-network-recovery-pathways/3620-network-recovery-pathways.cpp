class Solution {
public:
    using ll = long long;
    const ll INF = 1e18;

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indeg(n, 0);

        vector<int> costs;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            indeg[v]++;
            costs.push_back(w);
        }

        // Topological Sort
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for (auto &[v, w] : adj[u]) {
                indeg[v]--;

                if (indeg[v] == 0)
                    q.push(v);
            }
        }

        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()), costs.end());

        auto feasible = [&](int minEdge) {

            vector<ll> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {

                if (dist[u] == INF)
                    continue;

                // Offline intermediate node
                if (u != 0 && u != n - 1 && !online[u])
                    continue;

                for (auto &[v, w] : adj[u]) {

                    if (w < minEdge)
                        continue;

                    if (v != 0 && v != n - 1 && !online[v])
                        continue;

                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }

            return dist[n - 1] <= k;
        };

        int left = 0;
        int right = costs.size() - 1;

        int ans = -1;

        while (left <= right) {

            int mid = (left + right) / 2;

            int val = costs[mid];

            if (feasible(val)) {
                ans = val;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};