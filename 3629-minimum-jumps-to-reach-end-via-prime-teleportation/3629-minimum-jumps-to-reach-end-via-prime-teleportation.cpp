class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int maxVal = *max_element(nums.begin(), nums.end());

        // SPF sieve
        vector<int> spf(maxVal + 1);
        for (int i = 0; i <= maxVal; i++) spf[i] = i;

        for (int i = 2; i * i <= maxVal; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= maxVal; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }

        auto isPrime = [&](int x) {
            return x >= 2 && spf[x] == x;
        };

        unordered_map<int, vector<int>> mp;

        // map prime factor -> indexes divisible by that prime
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (x > 1) {
                int p = spf[x];
                mp[p].push_back(i);

                while (x % p == 0) {
                    x /= p;
                }
            }
        }

        queue<int> q;
        vector<int> dist(n, -1);

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1) return dist[i];

            // adjacent left
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            // adjacent right
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            // prime teleportation
            int val = nums[i];

            if (isPrime(val) && mp.count(val)) {
                for (int j : mp[val]) {
                    if (j != i && dist[j] == -1) {
                        dist[j] = dist[i] + 1;
                        q.push(j);
                    }
                }

                // important to avoid repeated work
                mp.erase(val);
            }
        }

        return dist[n - 1];
    }
};