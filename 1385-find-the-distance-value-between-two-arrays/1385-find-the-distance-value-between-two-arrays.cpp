class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // Sort arr2 to allow fast binary search lookups
        sort(arr2.begin(), arr2.end());
        int distance_value = 0;
        
        for (int x : arr1) {
            // Find the first element in arr2 that is >= x - d
            auto it = lower_bound(arr2.begin(), arr2.end(), x - d);
            
            // If such an element exists and it is also <= x + d,
            // it means |x - arr2[j]| <= d condition is met, so we skip x.
            if (it != arr2.end() && *it <= x + d) {
                continue;
            }
            
            // If no elements fall in the range [x - d, x + d], increment the count
            distance_value++;
        }
        
        return distance_value;
    }
};
