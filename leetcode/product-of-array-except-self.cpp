class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n+1);
        right[n] = 1;
        for (int i = n-1; i >= 0; --i)
            right[i] = right[i+1] * nums[i];
        vector<int> ans(n);
        int prod = 1;
        for (int i = 0; i < n; ++i) {
            ans[i] = prod * right[i+1];
            prod *= nums[i];
        }
        return ans;
    }
};