// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 0, hi = n;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            bool yes = isBadVersion(mi);
            if (yes) {
                hi = mi;
            }
            else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};