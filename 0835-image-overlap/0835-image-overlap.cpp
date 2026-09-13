class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                        vector<vector<int>>& img2) {

        int n = img1.size();
        int ans = 0;

        // Try every possible shift
        for (int dr = -(n - 1); dr <= n - 1; dr++) {

            for (int dc = -(n - 1); dc <= n - 1; dc++) {

                int overlap = 0;

                for (int i = 0; i < n; i++) {

                    for (int j = 0; j < n; j++) {

                        // New position of img1[i][j]
                        int ni = i + dr;
                        int nj = j + dc;

                        // Outside matrix
                        if (ni < 0 || ni >= n ||
                            nj < 0 || nj >= n) {
                            continue;
                        }

                        // Both images have 1
                        if (img1[i][j] == 1 &&
                            img2[ni][nj] == 1) {
                            overlap++;
                        }
                    }
                }

                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};