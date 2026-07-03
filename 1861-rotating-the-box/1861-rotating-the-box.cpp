class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for (int i = 0; i < m; i++) {
            int writeRow = n - 1;  // where next stone will fall

            for (int j = n - 1; j >= 0; j--) {
                char c = box[i][j];

                if (c == '*') {
                    ans[j][m - 1 - i] = '*';
                    writeRow = j - 1;  // reset due to obstacle
                } 
                else if (c == '#') {
                    ans[writeRow][m - 1 - i] = '#';
                    writeRow--;
                }
            }
        }

        return ans;
    }
};