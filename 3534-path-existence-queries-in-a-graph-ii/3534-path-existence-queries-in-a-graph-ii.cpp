class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back({nums[i], i});
        }

        sort(pairs.begin(), pairs.end());

        const int LOG = 20;
        vector<vector<int>> up(n, vector<int>(LOG));

        int r = n - 1;

        for (int l = n - 1; l >= 0; l--) {
            while (pairs[r].first - pairs[l].first > maxDiff) {
                r--;
            }

            int u = pairs[l].second;
            int v = pairs[r].second;

            up[u][0] = v;

            for (int k = 1; k < LOG; k++) {
                up[u][k] = up[up[u][k - 1]][k - 1];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            if (nums[u] > nums[v]) swap(u, v);

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (nums[u] == nums[v]) {
                ans.push_back(1);
                continue;
            }

            int dist = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (nums[up[u][k]] < nums[v]) {
                    dist += (1 << k);
                    u = up[u][k];
                }
            }

            if (nums[up[u][0]] < nums[v]) {
                ans.push_back(-1);
            } else {
                ans.push_back(dist + 1);
            }
        }

        return ans;
    }
};