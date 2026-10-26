class Solution {
    public int uniquePaths(int m, int n) {
       int[][] dp= new int[m][n];
       for(int[] row : dp){
        Arrays.fill(row,-1);
       }
        return helper(0,0,m-1,n-1,dp);
    }
    int helper(int sr,int sc, int er, int ec, int[][] dp){
        if(sr==er || sc==ec)return 1;
        if(sr>er || sc>ec)return 0;
        if(dp[sr][sc] != -1) return dp[sr][sc];
        return dp[sr][sc]=helper(sr,sc+1,er,ec,dp)+helper(sr+1,sc,er,ec,dp);
    }
}