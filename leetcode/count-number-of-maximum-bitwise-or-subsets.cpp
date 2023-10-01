class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int all = 0;
        for (int x : nums)
            all |= x;
        
        int cnt = 0;
        int n = size(nums);
        for (int x = 0; x < 1 << n; ++x) {
            // x is every permutation
            // since n <= 16
            int cur = 0;
            for (int i = 0; i < n; ++i)
                if (x & (1 << i))
                    cur |= nums[i];
            
            if (cur == all)
                ++cnt;
        }
        
        return cnt;
    }
};