class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            int be = 0;
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j])
                    be = max(be, dp[j]);
            dp[i] = be + 1;
        }
        return *max_element(begin(dp), end(dp));
    }
};