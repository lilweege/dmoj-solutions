class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (k*m > n)
            return -1;
        int hi = *max_element(begin(bloomDay), end(bloomDay));
        if (k*m == n)
            return hi;
        
        int ans = -1;
        int lo = 0;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            
            int cnt = 0;
            int run = 0;
            for (int i = 0; i < n; ++i) {
                if (bloomDay[i] > mi) {
                    run = 0;
                    if ((n-1-i) < (m-cnt)*k) {
                        lo = mi + 1;
                        break;
                    }
                    continue;
                }
                ++run;
                if (run == k) {
                    run = 0;
                    if (++cnt >= m) {
                        ans = mi;
                        hi = mi - 1;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};