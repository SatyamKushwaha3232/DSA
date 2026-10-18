import java.util.*;

class SegmentTree {
    private int n;
    private long[] sum_sq;
    private long[] sum_val;
    private long[] lazy;
    private final long MOD = 1000000007;

    private void push(int node, int start, int end) {
        if (lazy[node] == 0) return;
        
        long val = lazy[node];
        int mid = start + (end - start) / 2;
        
        int left_child = 2 * node;
        long left_len = mid - start + 1;
        sum_sq[left_child] = (sum_sq[left_child] + 2 * val * sum_val[left_child] % MOD + val * val % MOD * left_len % MOD) % MOD;
        sum_val[left_child] = (sum_val[left_child] + val * left_len) % MOD;
        lazy[left_child] = (lazy[left_child] + val) % MOD;
        
        int right_child = 2 * node + 1;
        long right_len = end - mid;
        sum_sq[right_child] = (sum_sq[right_child] + 2 * val * sum_val[right_child] % MOD + val * val % MOD * right_len % MOD) % MOD;
        sum_val[right_child] = (sum_val[right_child] + val * right_len) % MOD;
        lazy[right_child] = (lazy[right_child] + val) % MOD;
        
        lazy[node] = 0;
    }

    public SegmentTree(int n) {
        this.n = n;
        sum_sq = new long[4 * n];
        sum_val = new long[4 * n];
        lazy = new long[4 * n];
    }

    public void update(int node, int start, int end, int l, int r, long val) {
        if (r < start || end < l) return;
        
        if (l <= start && end <= r) {
            long length = end - start + 1;
            sum_sq[node] = (sum_sq[node] + 2 * val * sum_val[node] % MOD + val * val % MOD * length % MOD) % MOD;
            sum_val[node] = (sum_val[node] + val * length) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
            return;
        }
        
        push(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        
        sum_sq[node] = (sum_sq[2 * node] + sum_sq[2 * node + 1]) % MOD;
        sum_val[node] = (sum_val[2 * node] + sum_val[2 * node + 1]) % MOD;
    }

    public long getTotalSumSq() {
        return sum_sq[1];
    }
}

public class Solution {
    public int sumCounts(int[] nums) {
        int n = nums.length;
        long MOD = 1000000007;
        SegmentTree tree = new SegmentTree(n);
        Map<Integer, Integer> last_occurrence = new HashMap<>();
        long total_ans = 0;
        
        for (int j = 0; j < n; ++j) {
            int last_idx = last_occurrence.containsKey(nums[j]) ? last_occurrence.get(nums[j]) : -1;
            tree.update(1, 0, n - 1, last_idx + 1, j, 1);
            total_ans = (total_ans + tree.getTotalSumSq()) % MOD;
            last_occurrence.put(nums[j], j);
        }
        
        return (int) total_ans;
    }
}
