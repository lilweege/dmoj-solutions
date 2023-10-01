class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = size(nums);
        
        vector<int> rmin(n);
        rmin[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; --i)
            rmin[i] = min(rmin[i+1], nums[i]);

        
        int lmax = nums[0];
        for (int i = 1; i < n; ++i) {
            if (lmax <= rmin[i])
                return i;
            lmax = max(lmax, nums[i]);
        }
        return -1;
    }
};