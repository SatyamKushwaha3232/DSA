class Solution {
public:

    unordered_set<string> ans;

    void dfs(
        string &s,
        int index,
        int leftRem,
        int rightRem,
        int balance,
        string &current
    ) {

        // Invalid state
        if (balance < 0) {
            return;
        }

        // End of string
        if (index == s.length()) {

            if (leftRem == 0 &&
                rightRem == 0 &&
                balance == 0) {

                ans.insert(current);
            }

            return;
        }

        char ch = s[index];

        // Case 1: '('
        if (ch == '(') {

            // Option 1: Remove '('
            if (leftRem > 0) {
                dfs(
                    s,
                    index + 1,
                    leftRem - 1,
                    rightRem,
                    balance,
                    current
                );
            }

            // Option 2: Keep '('
            current.push_back('(');

            dfs(
                s,
                index + 1,
                leftRem,
                rightRem,
                balance + 1,
                current
            );

            current.pop_back();
        }

        // Case 2: ')'
        else if (ch == ')') {

            // Option 1: Remove ')'
            if (rightRem > 0) {
                dfs(
                    s,
                    index + 1,
                    leftRem,
                    rightRem - 1,
                    balance,
                    current
                );
            }

            // Option 2: Keep ')'
            if (balance > 0) {

                current.push_back(')');

                dfs(
                    s,
                    index + 1,
                    leftRem,
                    rightRem,
                    balance - 1,
                    current
                );

                current.pop_back();
            }
        }

        // Case 3: Letter
        else {

            current.push_back(ch);

            dfs(
                s,
                index + 1,
                leftRem,
                rightRem,
                balance,
                current
            );

            current.pop_back();
        }
    }


    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0;
        int rightRem = 0;

        // Calculate minimum removals
        for (char ch : s) {

            if (ch == '(') {
                leftRem++;
            }

            else if (ch == ')') {

                if (leftRem > 0) {
                    leftRem--;
                }
                else {
                    rightRem++;
                }
            }
        }

        string current = "";

        dfs(
            s,
            0,
            leftRem,
            rightRem,
            0,
            current
        );

        return vector<string>(ans.begin(), ans.end());
    }
};