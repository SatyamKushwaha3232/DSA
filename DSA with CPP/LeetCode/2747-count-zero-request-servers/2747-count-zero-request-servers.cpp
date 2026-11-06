class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int m = queries.size();

        vector<pair<int,int>> q;

        for(int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(m);

        int left = 0, right = 0;
        int active = 0;

        for(auto [time, idx] : q) {

            int start = time - x;

            // Add requests up to query time
            while(right < logs.size() &&
                  logs[right][1] <= time) {

                int id = logs[right][0];

                if(freq[id] == 0)
                    active++;

                freq[id]++;
                right++;
            }

            // Remove requests outside the window
            while(left < right &&
                  logs[left][1] < start) {

                int id = logs[left][0];

                freq[id]--;

                if(freq[id] == 0)
                    active--;

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};