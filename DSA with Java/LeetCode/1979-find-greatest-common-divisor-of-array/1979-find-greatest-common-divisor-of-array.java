class Solution {
    public int findGCD(int[] nums) {
        int min = nums[0];
        int max = nums[0];

        for (int num : nums) {
            if (num < min) min = num;
            if (num > max) max = num;
        }

        while (max != 0) {
            int temp = max;
            max = min % max;
            min = temp;
        }

        return min;
    }
}