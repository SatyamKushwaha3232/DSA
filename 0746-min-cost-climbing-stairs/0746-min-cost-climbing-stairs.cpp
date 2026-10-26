class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int p1=cost[1];
        int p2=cost[0];
        for(int i=2;i<n;i++){

            int curr=cost[i]+min(p1,p2);

            p2=p1;
            p1=curr;
        }

        return min(p1,p2);
 


        
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