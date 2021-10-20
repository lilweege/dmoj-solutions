// https://leetcode.com/problems/contiguous-array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(2 * n + 1, INT_MIN);
        v[n] = -1;
        int ans = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += (nums[i] == 0 ? -1 : 1);
            if (v[n + cnt] == INT_MIN)
                v[n + cnt] = i;
            else
                ans = max(ans, i - v[n + cnt]);
        }
        return ans;
    }
};