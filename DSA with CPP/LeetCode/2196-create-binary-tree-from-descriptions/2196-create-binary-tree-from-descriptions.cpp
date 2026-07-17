class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (auto &d : descriptions) {
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            if (!nodes.count(parent)) {
                nodes[parent] = new TreeNode(parent);
            }

            if (!nodes.count(child)) {
                nodes[child] = new TreeNode(child);
            }

            if (isLeft == 1) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }

            children.insert(child);
        }

        for (auto &it : nodes) {
            if (!children.count(it.first)) {
                return it.second;
            }
        }

        return NULL;
    }
};