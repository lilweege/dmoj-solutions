class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int lo = 0, hi = n-1;
        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (a[m] < a[hi]) {
                hi = m;
            }
            else {
                lo = m + 1;
            }
        }
        return a[hi];
    }
};