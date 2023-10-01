class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int tot = 0;
        for (int x : nums) tot += x;
        if (tot & 1) return false;
        int target = tot / 2;
        
        // 0/1 knapsack
        // dp[i][sum] = possible total is sum of nums up to i
        bool dp[201][20001]{};
        // for (int sum = 1; sum <= target; ++sum)
        //     dp[0][sum] = false;
        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
            dp[i][nums[0]] = true;
        }
        for (int i = 1; i < n; ++i)
            for (int sum = 1; sum <= tot; ++sum) {
                dp[i][sum] = dp[i-1][sum]; // don't take
                if (sum >= nums[i]) {
                    dp[i][sum] |= dp[i-1][sum-nums[i]]; // take
                }
            }
        return dp[n-1][target];
    }
};