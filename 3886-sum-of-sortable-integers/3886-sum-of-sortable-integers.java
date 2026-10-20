import java.util.ArrayList;
import java.util.List;

class Solution {
    public int sortableIntegers(int[] nums) {
        int n = nums.length;
        int totalSum = 0;
        
        // Step 1: Find all divisors of n
        List<Integer> divisors = new ArrayList<>();
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.add(i);
                if (i * i != n) {
                    divisors.add(n / i);
                }
            }
        }
        
        // Step 2: Validate each divisor k
        for (int k : divisors) {
            boolean valid = true;
            int prevMax = Integer.MIN_VALUE;
            
            for (int i = 0; i < n; i += k) {
                int minVal = Integer.MAX_VALUE;
                int maxVal = Integer.MIN_VALUE;
                int drops = 0;
                
                // Inspect the current block of size k
                for (int j = 0; j < k; j++) {
                    int curr = nums[i + j];
                    int next = nums[i + ((j + 1) % k)];
                    
                    if (curr > next) {
                        drops++;
                    }
                    if (curr < minVal) minVal = curr;
                    if (curr > maxVal) maxVal = curr;
                }
                
                // Criteria 1: Circularly sorted blocks can drop at most once
                if (drops > 1) {
                    valid = false;
                    break;
                }
                
                // Criteria 2: Global chaining condition
                if (minVal < prevMax) {
                    valid = false;
                    break;
                }
                
                prevMax = maxVal;
            }
            
            if (valid) {
                totalSum += k;
            }
        }
        
        return totalSum;
    }
}
