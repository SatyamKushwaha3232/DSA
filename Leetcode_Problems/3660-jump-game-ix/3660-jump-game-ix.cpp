class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }
        vector<int> ans(n);
        int start = 0;
        int currMax = nums[0];

        for (int i = 0; i < n; i++) {
            currMax = max(currMax, nums[i]);
            if (i == n - 1 || currMax <= suffixMin[i + 1]) {
                for (int j = start; j <= i; j++) {
                    ans[j] = currMax;
                }

                start = i + 1;
                if (start < n) {
                    currMax = nums[start];
                }
            }
        }
         return ans;
    }
};