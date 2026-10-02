class Solution {
public:

    void solve(int n, int open, int close,
               string current,
               vector<string>& ans) {

        // Complete valid string
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Add opening bracket
        if (open < n) {
            solve(n, open + 1, close,
                  current + "(", ans);
        }

        // Add closing bracket
        if (close < open) {
            solve(n, open, close + 1,
                  current + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        solve(n, 0, 0, "", ans);

        return ans;
    }
};