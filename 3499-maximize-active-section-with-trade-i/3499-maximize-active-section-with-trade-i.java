class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        char[] arr = s.toCharArray();

        int ones = 0;
        int prevZeros = 0;
        int best = 0;

        for (int i = 0; i < arr.length; i++) {

            int oneCnt = 0;
            while (i < arr.length && arr[i] == '1') {
                oneCnt++;
                ones++;
                i++;
            }

            int zeroCnt = 0;
            while (i < arr.length && arr[i] == '0') {
                zeroCnt++;
                i++;
            }

            if (prevZeros > 0 && oneCnt > 0 && zeroCnt > 0) {
                best = Math.max(best, prevZeros + zeroCnt);
            }

            prevZeros = zeroCnt;
            i--;
        }

        return ones + best;
    }
}