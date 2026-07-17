class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int freq[101] = {0};

        for (int c : cost) {
            freq[c]++;
        }

        int ans = 0;
        int count = 0;

        for (int price = 100; price >= 1; price--) {
            while (freq[price]--) {
                count++;

                // Every 3rd candy is free
                if (count % 3 != 0) {
                    ans += price;
                }
            }
        }

        return ans;
    }
};