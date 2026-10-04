class Solution {
public:
    bool checkValidString(string s) {

        int low = 0;
        int high = 0;

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }

            else if (ch == ')') {
                low--;
                high--;
            }

            else { // '*'

                // '*' can act as ')'
                low--;

                // '*' can act as '('
                high++;
            }

            // Maximum possible balance < 0
            // means no valid possibility exists
            if (high < 0)
                return false;

            // Minimum balance cannot be negative
            low = max(0, low);
        }

        // If balance 0 is possible
        return low == 0;
    }
};