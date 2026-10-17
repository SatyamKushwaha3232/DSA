
import java.util.*;

class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;
        int[][] arr = new int[n][2];

        // Store number and its digit sum
        for (int i = 0; i < n; i++) {
            arr[i][0] = nums[i];
            arr[i][1] = digitSum(nums[i]);
        }

        // Sort by digit sum, then by number
        Arrays.sort(arr, (a, b) -> {
            if (a[1] != b[1]) {
                return Integer.compare(a[1], b[1]);
            }
            return Integer.compare(a[0], b[0]);
        });

        // Map each number to its original index
        Map<Integer, Integer> indexMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            indexMap.put(nums[i], i);
        }

        boolean[] visited = new boolean[n];
        int swaps = 0;

        // Count cycles in the permutation
        for (int i = 0; i < n; i++) {
            if (visited[i] || indexMap.get(arr[i][0]) == i) {
                visited[i] = true;
                continue;
            }

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = indexMap.get(arr[j][0]);
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }

    private int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}
