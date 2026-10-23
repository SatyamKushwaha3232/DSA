class Solution {
    public int sortPermutation(int[] nums) {
        // Initialize ans with all bits set (-1 represents all 1s in two's complement)
        int ans = -1;
        boolean isSorted = true;
        
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != i) {
                ans &= nums[i];
                isSorted = false;
            }
        }
        
        // If the array is already sorted, return 0
        return isSorted ? 0 : ans;
    }
}
