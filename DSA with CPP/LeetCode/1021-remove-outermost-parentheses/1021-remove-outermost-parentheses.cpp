class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans = "";
        int balance = 0;

        for (char ch : s) {

            // Opening parenthesis
            if (ch == '(') {

                // Add only if it is NOT outermost '('
                if (balance > 0) {
                    ans += ch;
                }

                balance++;
            }

            // Closing parenthesis
            else {

                balance--;

                // Add only if it is NOT outermost ')'
                if (balance > 0) {
                    ans += ch;
                }
            }
        }

        return ans;
    }
};