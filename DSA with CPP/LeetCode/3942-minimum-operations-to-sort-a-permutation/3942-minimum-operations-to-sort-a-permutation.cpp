#include <vector>
#include <algorithm>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        // Find the index of 0
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx = i;
                break;
            }
        }
        
        // Check if it's increasing to the right
        bool is_increasing = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(idx + i) % n] != i) {
                is_increasing = false;
                break;
            }
        }
        
        // Check if it's decreasing to the right (increasing to the left)
        bool is_decreasing = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(idx - i + n) % n] != i) {
                is_decreasing = false;
                break;
            }
        }
        
        int ans = 1e9;
        
        if (is_increasing) {
            // Case 1: Pure left rotations
            ans = std::min(ans, idx);
            // Case 2: Reverse, left rotate, reverse
            ans = std::min(ans, 2 + (n - idx));
        }
        
        if (is_decreasing) {
            // Case 3: Rotate left to put 0 at the end, then reverse
            ans = std::min(ans, idx + 2);
            // Case 4: Reverse, then rotate left to put 0 at the beginning
            ans = std::min(ans, n - idx);
        }
        
        return (ans == 1e9) ? -1 : ans;
    }
};
