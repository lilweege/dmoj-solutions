// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -INT_MAX, s = 0;
        for (int x : nums) {
            s += x;
            ans = max(ans, s);
            s = max(s, 0);
        }
        return ans;
    }
};