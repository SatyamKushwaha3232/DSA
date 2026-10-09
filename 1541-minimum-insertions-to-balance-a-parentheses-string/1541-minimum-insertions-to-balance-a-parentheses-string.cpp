
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int open = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                open++;
            }
            else {
                // If the next character is not ')',
                // insert one ')' to form a pair.
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } else {
                    ans++;
                }

                // Match this '))' pair with an opening '('.
                if (open > 0) {
                    open--;
                } else {
                    // No opening '(' exists: insert one '('.
                    ans++;
                }
            }
        }

        // Each unmatched '(' needs two closing ')'.
        ans += 2 * open;

        return ans;
    }
};
