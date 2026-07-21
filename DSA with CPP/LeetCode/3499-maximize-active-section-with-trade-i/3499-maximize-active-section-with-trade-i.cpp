class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        int active = 0;
        for (char c : s)
            if (c == '1') active++;

        string t = "1" + s + "1";
        int m = t.size();

        vector<int> leftOne(m, -1), rightOne(m, -1);

        for (int i = 0; i < m; i++) {
            if (t[i] == '1')
                leftOne[i] = i;
            else if (i)
                leftOne[i] = leftOne[i - 1];
        }

        for (int i = m - 1; i >= 0; i--) {
            if (t[i] == '1')
                rightOne[i] = i;
            else if (i + 1 < m)
                rightOne[i] = rightOne[i + 1];
        }

        int ans = active;

        for (int i = 1; i < m - 1;) {
            if (t[i] == '1') {
                int j = i;
                while (j < m && t[j] == '1') j++;

                if (i > 0 && j < m && t[i - 1] == '0' && t[j] == '0') {
                    int L = leftOne[i - 1];
                    int R = rightOne[j];

                    if (L != -1 && R != -1) {
                        int gain = R - L - 1;
                        int lost = j - i;
                        ans = max(ans, active + gain - lost);
                    }
                }
                i = j;
            } else {
                i++;
            }
        }

        return ans;
    }
};