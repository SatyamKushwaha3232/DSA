class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

        vector<int> ans(seq.size());

        int depth = 0;

        for (int i = 0; i < seq.size(); i++) {

            if (seq[i] == '(') {
                depth++;

                // Odd depth -> group 1
                // Even depth -> group 0
                ans[i] = depth % 2;
            }
            else {
                // Closing bracket belongs to the
                // same group as its opening bracket
                ans[i] = depth % 2;

                depth--;
            }
        }

        return ans;
    }
};