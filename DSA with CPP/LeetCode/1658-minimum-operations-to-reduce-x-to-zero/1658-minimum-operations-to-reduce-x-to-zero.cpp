class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        long long total = 0;

        for (int num : nums) {
            total += num;
        }

        // We need to keep a subarray
        // whose sum is total - x.
        long long target = total - x;

        // If target is negative,
        // impossible.
        if (target < 0) {
            return -1;
        }

        // target = 0 means remove all elements.
        if (target == 0) {
            return n;
        }

        int left = 0;
        long long sum = 0;

        int maxLen = -1;

        for (int right = 0; right < n; right++) {

            sum += nums[right];

            // Shrink window if sum becomes too large
            while (left <= right && sum > target) {
                sum -= nums[left];
                left++;
            }

            // Found required subarray
            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        // No such subarray
        if (maxLen == -1) {
            return -1;
        }

        // Everything outside the subarray is removed.
        return n - maxLen;
    }
};

