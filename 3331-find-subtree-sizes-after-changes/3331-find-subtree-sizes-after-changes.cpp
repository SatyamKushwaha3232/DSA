class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> head(n, -1), nxt(n, -1), prev(n, -1), order, stack, ans(n, 1), last(26, -1);
        order.reserve(n);
        stack.reserve(n);

        for (int i = n - 1; i >= 1; i--) {
            nxt[i] = head[parent[i]];
            head[parent[i]] = i;
        }

        stack.push_back(0);
        last[s[0] - 'a'] = 0;
        order.push_back(0);

        while (!stack.empty()) {
            int u = stack.back();
            int v = head[u];
            if (v != -1) {
                head[u] = nxt[v];
                int ch = s[v] - 'a';
                prev[v] = last[ch];
                last[ch] = v;
                order.push_back(v);
                stack.push_back(v);
            } else {
                last[s[u] - 'a'] = prev[u];
                stack.pop_back();
            }
        }

        for (int k = n - 1; k >= 1; k--) {
            int x = order[k];
            int p = prev[x] != -1 ? prev[x] : parent[x];
            ans[p] += ans[x];
        }
        return ans;
    }
};