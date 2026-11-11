
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long common = min(need1, need2);
        long long extra1 = max(0, need1 - need2);
        long long extra2 = max(0, need2 - need1);

        // Option 1: Use common items for overlapping needs
        long long ans1 = common * costBoth
                       + extra1 * cost1
                       + extra2 * cost2;

        // Option 2: Use only common items
        long long ans2 = 1LL * max(need1, need2) * costBoth;

        // Option 3: Buy everything separately
        long long ans3 = 1LL * need1 * cost1
                       + 1LL * need2 * cost2;

        return min({ans1, ans2, ans3});
    }
};

