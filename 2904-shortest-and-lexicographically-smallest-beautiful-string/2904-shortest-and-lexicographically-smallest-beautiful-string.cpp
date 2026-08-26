class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        string ans = "";

        for (int i = 0; i < n; i++) {
            int ones = 0;

            for (int j = i; j < n; j++) {
                if (s[j] == '1') {
                    ones++;
                }

                if (ones == k) {
                    string curr = s.substr(i, j - i + 1);

                    // Remove leading zeros
                    int start = 0;
                    while (start < curr.size() && curr[start] == '0') {
                        start++;
                    }

                    curr = curr.substr(start);

                    if (ans.empty() ||
                        curr.length() < ans.length() ||
                        (curr.length() == ans.length() && curr < ans)) {
                        ans = curr;
                    }

                    break;
                }
            }
        }

        return ans;
    }
};
