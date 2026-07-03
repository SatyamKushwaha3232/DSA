class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, F = 0;

        // Compute sum and F(0)
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += (long long)i * nums[i];
        }

        long long maxVal = F;

        // Compute all rotations
        for (int k = 1; k < n; k++) {
            F = F + sum - (long long)n * nums[n - k];
            maxVal = max(maxVal, F);
        }

        return maxVal;
    }
};