class Solution {
    public int tribonacci(int n) {

        // Base cases
        if (n == 0)
            return 0;

        if (n == 1 || n == 2)
            return 1;

        // Previous three values
        int prev3 = 0; // T0
        int prev2 = 1; // T1
        int prev1 = 1; // T2

        // Calculate from T3 to Tn
        for (int i = 3; i <= n; i++) {

            int curr = prev1 + prev2 + prev3;

            // Shift values
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
}