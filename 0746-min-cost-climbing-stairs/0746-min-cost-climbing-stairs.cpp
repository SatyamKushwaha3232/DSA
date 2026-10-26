class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();

        for(int i=2;i<n;i++){

         cost[i] += min(cost[i-1],cost[i-2]);


        }

        return min(cost[n-1],cost[n-2]);
 


        
    }
};
// class Solution {
// public:
//     vector<int> dp;
//     int ftd(vector<int> cost, int i, vector<int> dp){
//          int n = cost.size();

//         if (i >= n)
//             return 0;

//         if(dp[i] != -1)
//         return dp[i];

//         return dp[i]=cost[i]+min(ftd(cost,i+2,dp), ftd(cost,i+1,dp));
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         dp.clear();
//         dp.resize(cost.size(),-1);
//         return min(ftd(cost,0,dp),ftd(cost,1,dp));
        
//     }
// };