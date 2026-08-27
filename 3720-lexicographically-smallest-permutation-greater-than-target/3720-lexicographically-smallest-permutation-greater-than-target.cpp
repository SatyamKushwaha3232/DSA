class Solution {
public:
    string s, target;
    int n;
    int memo[305][2][2];

    // state:
    // pos     = current position
    // greater = whether prefix is already greater than target
    //
    // Returns whether we can construct a valid permutation.
    bool possible(int pos, bool greater, vector<int>& cnt) {
        if (pos == n)
            return greater;

        int state = greater ? 1 : 0;

        // We cannot memoize directly with cnt because cnt changes.
        // So this function is not used for general memoization.
        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        this->s = s;
        this->target = target;
        n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        string ans;

        /*
            We maintain two possibilities:

            equal:
                prefix == target prefix

            greater:
                prefix > target prefix

            Once greater, simply use smallest remaining characters.
        */

        for (int i = 0; i < n; i++) {

            int t = target[i] - 'a';

            // We are currently equal to target.

            // First try to keep the prefix equal.
            if (cnt[t] > 0) {
                ans += target[i];
                cnt[t]--;
                continue;
            }

            /*
                Equal is impossible at this position.

                Now we need to make the answer greater.

                But we should NOT necessarily backtrack immediately
                to the previous position.

                Try to put the smallest character > target[i].
            */
            for (int c = t + 1; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                string res = ans;
                res += char('a' + c);

                cnt[c]--;

                // Remaining characters in sorted order.
                for (int k = 0; k < 26; k++)
                    res.append(cnt[k], char('a' + k));

                return res;
            }

            /*
                No greater character exists at this position.
                Therefore we have to backtrack.
            */

            for (int j = i - 1; j >= 0; j--) {

                // Restore character at position j.
                cnt[ans[j] - 'a']++;

                int tj = target[j] - 'a';

                // Find smallest character > target[j].
                for (int c = tj + 1; c < 26; c++) {

                    if (cnt[c] == 0)
                        continue;

                    string res = ans.substr(0, j);
                    res += char('a' + c);

                    cnt[c]--;

                    // Fill suffix minimally.
                    for (int k = 0; k < 26; k++)
                        res.append(cnt[k], char('a' + k));

                    return res;
                }
            }

            return "";
        }

        /*
            Entire target can be formed.

            target itself is a permutation of s.
            We need the next permutation.
        */

        string res = target;

        int i = n - 2;

        while (i >= 0 && res[i] >= res[i + 1])
            i--;

        if (i < 0)
            return "";

        int j = n - 1;

        while (res[j] <= res[i])
            j--;

        swap(res[i], res[j]);

        reverse(res.begin() + i + 1, res.end());

        return res;
    }
};