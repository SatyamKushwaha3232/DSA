class Solution {
public:
    static const int MOD = 1000000007;

    struct Node {
        long long val;
        int sum;
        int cnt;
    };

    vector<Node> seg;
    vector<long long> pw;

    Node merge(Node a, Node b) {
        Node res;
        res.val = (a.val * pw[b.cnt] + b.val) % MOD;
        res.sum = a.sum + b.sum;
        res.cnt = a.cnt + b.cnt;
        return res;
    }

    void build(int idx, int l, int r, string &s) {
        if (l == r) {
            int d = s[l] - '0';
            if (d == 0)
                seg[idx] = {0, 0, 0};
            else
                seg[idx] = {d, d, 1};
            return;
        }

        int mid = (l + r) / 2;
        build(idx * 2, l, mid, s);
        build(idx * 2 + 1, mid + 1, r, s);

        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(idx * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(idx * 2 + 1, mid + 1, r, ql, qr);

        return merge(
            query(idx * 2, l, mid, ql, qr),
            query(idx * 2 + 1, mid + 1, r, ql, qr)
        );
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        pw.resize(n + 1);
        pw[0] = 1;

        for (int i = 1; i <= n; i++)
            pw[i] = (pw[i - 1] * 10) % MOD;

        seg.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            Node cur = query(1, 0, n - 1, q[0], q[1]);
            ans.push_back((cur.val * cur.sum) % MOD);
        }

        return ans;
    }
};