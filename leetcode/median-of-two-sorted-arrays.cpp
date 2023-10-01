class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // O(n+m)
        
        size_t n = nums1.size();
        size_t m = nums2.size();
        size_t sz = m + n;
        bool twoMids = (sz & 1) == 0;
        
        double ans = 0;
        
        int lastVal;
        size_t i = 0;
        size_t j = 0;
        while (i < n || j < m) {
            int x1 = i >= n ? INT_MAX : nums1[i];
            int x2 = j >= m ? INT_MAX : nums2[j];
            if (x1 > x2) {
                lastVal = x2;
                ++j;
            }
            else {
                lastVal = x1;
                ++i;
            }
            
            if (twoMids) {
                if (i+j == sz/2) {
                    ans = lastVal;
                }
                else if (i+j == sz/2+1) {
                    return (ans + lastVal) / 2;
                }
            }
            else {
                if (i+j == sz/2+1) {
                    return lastVal;
                }
            }
        }
        return -69;
    }
};