class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            int reversePos = 'z' - s[i] + 1;
            int stringPos = i + 1;

            ans += reversePos * stringPos;
        }

        return ans;
    }
};