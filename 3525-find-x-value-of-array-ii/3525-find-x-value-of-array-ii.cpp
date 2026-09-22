class Solution {
public:
    struct Node {
        int prod;
        int pref[5];

        Node() {
            prod = 1;

            for (int i = 0; i < 5; i++) {
                pref[i] = 0;
            }
        }
    };

    int n, k;
    vector<Node> tree;

    // Merge two consecutive segments:
    // left + right
    Node mergeNode(const Node& left, const Node& right) {

        Node res;

        // Product of complete segment
        res.prod = (left.prod * right.prod) % k;

        // Prefixes completely inside left
        for (int r = 0; r < k; r++) {
            res.pref[r] += left.pref[r];
        }

        // Prefixes which contain all of left
        // and then take a prefix of right
        for (int r = 0; r < k; r++) {

            int newRem = (left.prod * r) % k;

            res.pref[newRem] += right.pref[r];
        }

        return res;
    }

    void build(vector<int>& nums) {

        // Leaves
        for (int i = 0; i < n; i++) {

            int rem = nums[i] % k;

            tree[n + i].prod = rem;
            tree[n + i].pref[rem] = 1;
        }

        // Internal nodes
        for (int i = n - 1; i >= 1; i--) {
            tree[i] = mergeNode(tree[i << 1],
                                 tree[i << 1 | 1]);
        }
    }

    void update(int pos, int value) {

        pos += n;

        int rem = value % k;

        tree[pos] = Node();

        tree[pos].prod = rem;
        tree[pos].pref[rem] = 1;

        pos >>= 1;

        while (pos >= 1) {

            tree[pos] = mergeNode(tree[pos << 1],
                                   tree[pos << 1 | 1]);

            pos >>= 1;
        }
    }

    Node query(int l, int r) {
        // Query [l, r)
        Node leftResult;
        Node rightResult;

        l += n;
        r += n;

        while (l < r) {

            if (l & 1) {
                leftResult =
                    mergeNode(leftResult, tree[l]);
                l++;
            }

            if (r & 1) {
                --r;

                rightResult =
                    mergeNode(tree[r], rightResult);
            }

            l >>= 1;
            r >>= 1;
        }

        return mergeNode(leftResult, rightResult);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        this->n = nums.size();
        this->k = k;

        tree.resize(2 * n);

        build(nums);

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            nums[index] = value;
            update(index, value);

            // Get nums[start ... n-1]
            Node res = query(start, n);

            answer.push_back(res.pref[x]);
        }

        return answer;
    }
};

