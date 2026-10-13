
import java.util.*;

class Solution {
    public int maxSum(List<Integer> nums, int k) {
        final long MOD = 1_000_000_007L;
        int[] bitCount = new int[31];

        // Count set bits at every position
        for (int num : nums) {
            for (int b = 0; b < 31; b++) {
                if ((num & (1 << b)) != 0) {
                    bitCount[b]++;
                }
            }
        }

        long sum = 0;

        // Construct k maximum possible numbers
        for (int i = 0; i < k; i++) {
            long x = 0;

            for (int b = 0; b < 31; b++) {
                if (bitCount[b] > 0) {
                    x |= (1L << b);
                    bitCount[b]--;
                }
            }

            sum = (sum + (x * x) % MOD) % MOD;
        }

        return (int) sum;
    }
}
