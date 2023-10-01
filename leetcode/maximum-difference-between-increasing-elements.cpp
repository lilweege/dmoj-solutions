class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // int n = size(nums);
        // int best = -1;
        // for (int i = 0; i < n; ++i)
        //     for (int j = i+1; j < n; ++j) {
        //         int diff = nums[j] - nums[i];
        //         if (diff > 0)
        //             best = max(best, diff);
        //     }
        // return best;
        
        
        // int n = size(nums);
        // vector<int> rmax(n);
        // rmax[n-1] = nums[n-1];
        // for (int i = n-2; i >= 0; --i) {
        //     rmax[i] = max(rmax[i+1], nums[i]);
        // }
        // int best = -1;
        // int lmin = nums[0];
        // for (int i = 1; i < n; ++i) {
        //     lmin = min(lmin, nums[i]);
        //     int diff = rmax[i] - lmin;
        //     if (diff > 0)
        //         best = max(best, diff);
        // }
        // return best;
        
        int n = size(nums);
        int lmin = nums[0];
        int best = -1;
        for (int i = 1; i < n; ++i) {
            lmin = min(lmin, nums[i]);
            int diff = nums[i] - lmin;
            if (diff > 0)
                best = max(best, nums[i] - lmin);
        }
        return best;
    }
};