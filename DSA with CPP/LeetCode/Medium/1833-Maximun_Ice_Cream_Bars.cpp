class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        static int freq[100001];
        memset(freq, 0, sizeof(freq));

        int maxCost = 0;

        for (int c : costs) {
            ++freq[c];
            if (c > maxCost) maxCost = c;
        }

        int ans = 0;

        for (int price = 1; price <= maxCost && coins >= price; ++price) {
            if (!freq[price]) continue;

            int take = min(freq[price], coins / price);

            ans += take;
            coins -= take * price;
        }

        return ans;
    }
};