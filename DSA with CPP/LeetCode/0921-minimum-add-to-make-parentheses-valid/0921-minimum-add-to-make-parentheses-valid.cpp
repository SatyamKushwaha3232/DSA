class Solution {
public:
    int minAddToMakeValid(string s) {

        int balance = 0;
        int ans = 0;

        for (char ch : s) {

            if (ch == '(') {
                balance++;
            }
            else {
                if (balance > 0) {
                    balance--;
                }
                else {
                    // Need an opening bracket
                    ans++;
                }
            }
        }

        // Remaining '(' need closing brackets
        ans += balance;

        return ans;
    }
};