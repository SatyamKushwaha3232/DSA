// class Solution {
// public:
//     int uniquePaths(int m, int n) {

//         vector<int> prev(n, 1);

//         for (int i = 1; i < m; i++) {

//             vector<int> curr(n, 1);

//             for (int j = 1; j < n; j++) {
//                 curr[j] = curr[j - 1] + prev[j];
//             }

//             prev = curr;
//         }

//         return prev[n - 1];
//     }
// };
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];

    }
};