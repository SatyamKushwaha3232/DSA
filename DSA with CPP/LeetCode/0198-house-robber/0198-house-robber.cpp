class Solution {
public:
    vector<int> dp;
    int ftd(vector<int> arr, int i){
        if(i==arr.size()-1)
        return arr[i];
        if(i==arr.size()-2)
        return max(arr[i],arr[i+1]);
        if(dp[i] != -1)
        return dp[i];

        return dp[i]=max(arr[i]+ftd(arr,i+2), 0+ftd(arr,i+1));
    }
    int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(105,-1);
        return ftd(nums,0);
        
    }
};