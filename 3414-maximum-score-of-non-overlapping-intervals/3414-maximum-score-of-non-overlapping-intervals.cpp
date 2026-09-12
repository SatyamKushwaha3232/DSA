class Solution {
public:
    struct State {
        long long score;
        vector<int> indices;
    };

    vector<vector<State>> memo;
    vector<vector<int>> intervals;
    vector<int> starts;
    int n;

    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.indices < b.indices;
    }

    int getNext(int i) {
        int target = intervals[i][1] + 1;

        int low = i + 1;
        int high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (starts[mid] >= target)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }

    State solve(int i, int k) {
        if (i == n || k == 0) {
            return {0, {}};
        }

        State &res = memo[i][k];

        if (res.score != -1)
            return res;

        // Option 1: Skip current interval
        State skip = solve(i + 1, k);

        // Option 2: Take current interval
        int next = getNext(i);

        State take = solve(next, k - 1);

        take.score += intervals[i][2];
        take.indices.push_back(intervals[i][3]);

        sort(take.indices.begin(), take.indices.end());

        if (better(take, skip))
            res = take;
        else
            res = skip;

        return res;
    }

    vector<int> maximumWeight(vector<vector<int>>& input) {
        n = input.size();

        intervals.clear();

        // Add original index
        for (int i = 0; i < n; i++) {
            intervals.push_back({
                input[i][0],
                input[i][1],
                input[i][2],
                i
            });
        }

        // Sort by starting position
        sort(intervals.begin(), intervals.end());

        starts.resize(n);

        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i][0];
        }

        // memo[i][k]
        memo.assign(n, vector<State>(5, {-1, {}}));

        return solve(0, 4).indices;
    }
};