class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> numbers;

        int n = digits.size();

        for (int i = 0; i < n; i++) {

            // First digit cannot be 0
            if (digits[i] == 0)
                continue;

            for (int j = 0; j < n; j++) {

                // Same copy cannot be used twice
                if (j == i)
                    continue;

                for (int k = 0; k < n; k++) {

                    // Same copy cannot be reused
                    if (k == i || k == j)
                        continue;

                    // Last digit must be even
                    if (digits[k] % 2 != 0)
                        continue;

                    int num = digits[i] * 100
                            + digits[j] * 10
                            + digits[k];

                    numbers.insert(num);
                }
            }
        }

        return numbers.size();
    }
};