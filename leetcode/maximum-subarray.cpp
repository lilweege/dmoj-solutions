class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e5;
        int run = 0;
        for (int x : nums) {
            ans = max(ans, run + x);
            run += x;
            if (run < 0) run = 0;
        }
        return ans;
    }
};