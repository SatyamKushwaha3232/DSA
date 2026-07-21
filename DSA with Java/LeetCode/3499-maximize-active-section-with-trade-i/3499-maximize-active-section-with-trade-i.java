class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int n = s.length();
        int active = 0;

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '1') active++;
        }

        char[] t = new char[n + 2];
        t[0] = '1';
        t[n + 1] = '1';
        for (int i = 0; i < n; i++) {
            t[i + 1] = s.charAt(i);
        }

        int m = n + 2;

        int[] leftOne = new int[m];
        int[] rightOne = new int[m];

        leftOne[0] = (t[0] == '1') ? 0 : -1;
        for (int i = 1; i < m; i++) {
            leftOne[i] = (t[i] == '1') ? i : leftOne[i - 1];
        }

        rightOne[m - 1] = (t[m - 1] == '1') ? (m - 1) : -1;
        for (int i = m - 2; i >= 0; i--) {
            rightOne[i] = (t[i] == '1') ? i : rightOne[i + 1];
        }

        int ans = active;

        int i = 1;
        while (i < m - 1) {
            if (t[i] == '1') {
                int j = i;
                while (j < m && t[j] == '1') j++;

                if (t[i - 1] == '0' && j < m && t[j] == '0') {
                    int L = leftOne[i - 1];
                    int R = rightOne[j];

                    if (L != -1 && R != -1) {
                        int gain = R - L - 1;
                        int loss = j - i;
                        ans = Math.max(ans, active + gain - loss);
                    }
                }
                i = j;
            } else {
                i++;
            }
        }

        return ans;
    }
}