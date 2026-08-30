class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find minimum and maximum indexes
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }

            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        // Case 1: Remove both from front
        int front = max(minIndex, maxIndex) + 1;

        // Case 2: Remove both from back
        int back = n - min(minIndex, maxIndex);

        // Case 3: One from front, one from back
        int both = min(minIndex, maxIndex) + 1
                 + n - max(minIndex, maxIndex);

        return min({front, back, both});
    }
};