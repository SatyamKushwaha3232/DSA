class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if (n != goal.size()) return false;

        for (int k = 0; k < n; k++) {
            int i = 0;

            while (i < n && s[(i + k) % n] == goal[i]) {
                i++;
            }

            if (i == n) return true;
        }

        return false;
    }
};