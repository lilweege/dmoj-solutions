class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // // naive implementation
        // // this is not constant space
        // unordered_map<int, bool> has;
        // for (int x : nums) {
        //     if (x < 1)
        //         continue;
        //     has[x] = true;
        // }
        // int n = size(nums);
        // int i = 1;
        // for (; i <= n; ++i)
        //     if (!has[i])
        //         return i;
        // return i;
        
        int n = size(nums);
        auto good = [=](int x) { return x > 0 && x <= n; };
        
        for (int& x : nums)
            if (!good(x))
                x = -1;
        
        for (int x : nums)
            while (good(x) && x != nums[x-1])
                swap(x, nums[x-1]);
        
        for (int i = 1; i <= n; ++i)
            if (nums[i-1] != i)
                return i;
        
        return n+1;
    }
};