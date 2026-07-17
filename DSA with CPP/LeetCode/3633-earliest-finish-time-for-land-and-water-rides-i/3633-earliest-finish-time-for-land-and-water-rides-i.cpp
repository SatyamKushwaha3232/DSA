class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            int landEnd = landStartTime[i] + landDuration[i];

            for (int j = 0; j < m; j++) {
                int waterEnd = waterStartTime[j] + waterDuration[j];

                // land first then water
                ans = min(ans, max(landEnd, waterStartTime[j]) + waterDuration[j]);

                // water first then land
                ans = min(ans, max(waterEnd, landStartTime[i]) + landDuration[i]);
            }
        }

        return ans;
    }
};