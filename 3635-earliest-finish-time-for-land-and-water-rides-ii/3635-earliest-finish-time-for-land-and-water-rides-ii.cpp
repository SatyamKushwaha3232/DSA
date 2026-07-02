class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int ans = INT_MAX;

        auto build = [](vector<int>& start, vector<int>& duration) {
            int n = start.size();

            vector<pair<int,int>> rides;
            for (int i = 0; i < n; i++) {
                rides.push_back({start[i], duration[i]});
            }

            sort(rides.begin(), rides.end());

            vector<int> starts(n);
            vector<int> prefixMinDur(n);
            vector<int> suffixMinEnd(n);

            for (int i = 0; i < n; i++) {
                starts[i] = rides[i].first;
            }

            prefixMinDur[0] = rides[0].second;
            for (int i = 1; i < n; i++) {
                prefixMinDur[i] = min(prefixMinDur[i - 1], rides[i].second);
            }

            suffixMinEnd[n - 1] = rides[n - 1].first + rides[n - 1].second;
            for (int i = n - 2; i >= 0; i--) {
                suffixMinEnd[i] = min(suffixMinEnd[i + 1],
                                      rides[i].first + rides[i].second);
            }

            return tuple<vector<int>, vector<int>, vector<int>>(starts, prefixMinDur, suffixMinEnd);
        };

        auto landData = build(landStartTime, landDuration);
        auto waterData = build(waterStartTime, waterDuration);

        auto getBest = [](int t, vector<int>& starts, vector<int>& prefixMinDur,
                          vector<int>& suffixMinEnd) {
            
            int n = starts.size();
            int ans = INT_MAX;

            int idx = upper_bound(starts.begin(), starts.end(), t) - starts.begin() - 1;

            // rides already open
            if (idx >= 0) {
                ans = min(ans, t + prefixMinDur[idx]);
            }

            // rides not open yet
            if (idx + 1 < n) {
                ans = min(ans, suffixMinEnd[idx + 1]);
            }

            return ans;
        };

        auto &[landStarts, landPrefixDur, landSuffixEnd] = landData;
        auto &[waterStarts, waterPrefixDur, waterSuffixEnd] = waterData;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        // Land first → Water second
        for (int i = 0; i < n; i++) {
            int landEnd = landStartTime[i] + landDuration[i];

            ans = min(ans, getBest(landEnd, waterStarts, waterPrefixDur, waterSuffixEnd));
        }

        // Water first → Land second
        for (int j = 0; j < m; j++) {
            int waterEnd = waterStartTime[j] + waterDuration[j];

            ans = min(ans, getBest(waterEnd, landStarts, landPrefixDur, landSuffixEnd));
        }

        return ans;
    }
};