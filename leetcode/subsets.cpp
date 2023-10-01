class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int x = 1 << n;
        vector<vector<int>> ans(x);
        for (int i = 0; i < x; ++i) {
            auto& v = ans[i];
            int idx = 0;
            for (int b = i; b > 0; b >>= 1) {
                if (b & 1) {
                    v.push_back(nums[idx]);
                }
                ++idx;
            }
        }
        return ans;
    }
};