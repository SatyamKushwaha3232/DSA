class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> present(MAXX, false);
        for (int x : nums)
            present[x] = true;

        vector<bool> pairXor(MAXX, false);

        // All possible XORs of two chosen values (same value allowed)
        for (int a = 0; a < MAXX; a++) {
            if (!present[a]) continue;
            for (int b = 0; b < MAXX; b++) {
                if (!present[b]) continue;
                pairXor[a ^ b] = true;
            }
        }

        vector<bool> ans(MAXX, false);

        // XOR with the third value
        for (int x = 0; x < MAXX; x++) {
            if (!pairXor[x]) continue;
            for (int c = 0; c < MAXX; c++) {
                if (!present[c]) continue;
                ans[x ^ c] = true;
            }
        }

        int count = 0;
        for (bool ok : ans)
            if (ok) count++;

        return count;
    }
};
