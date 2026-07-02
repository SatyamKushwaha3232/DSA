class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int totalSum = 0;

        for (int x : nums) {
            totalSum += x;
        }

        vector<int> ans(nums.size());

        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            int rightSum = totalSum - leftSum - nums[i];

            ans[i] = abs(leftSum - rightSum);

            leftSum += nums[i];
        }

        return ans;
    }
};