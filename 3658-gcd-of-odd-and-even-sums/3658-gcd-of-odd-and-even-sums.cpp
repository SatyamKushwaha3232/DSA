class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int summ1 = n*(2*n+1);
        int eveny = n*(n+1);
        return __gcd(eveny,summ1-eveny);
    }
};