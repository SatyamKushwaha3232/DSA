class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        const int INF = 1e9;

        // best[i] = index 0 to i tak mila
        // minimum length ka target-sum subarray
        vector<int> best(n, INF);

        int ans = INF;
        int left = 0;
        long long sum = 0;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            // Window ko chhota karo
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Current window ka sum target hai
            if (sum == target) {
                int len = right - left + 1;

                // Left side mein pehle se valid subarray hai
                if (left > 0 && best[left - 1] != INF) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Current position tak minimum valid length
                if (right == 0) {
                    best[right] = len;
                } else {
                    best[right] = min(best[right - 1], len);
                }
            } 
            else {
                // Current position tak previous best carry karo
                if (right > 0) {
                    best[right] = best[right - 1];
                }
            }
        }

        return ans == INF ? -1 : ans;
    }
};
