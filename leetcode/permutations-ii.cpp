class Solution {
    void dfs(vector<int>& nums, vector<vector<int>>& out, size_t i=0) {
        size_t n = nums.size();
        if (i == n-1) {
            out.push_back(nums);
            return;
        }
        
        for (size_t j = i; j < n; ++j) {
            swap(nums[i], nums[j]);
            dfs(nums, out, i+1);
            swap(nums[i], nums[j]);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums, ans);
        
        // lol
        sort(ans.begin(), ans.end());
        auto last = std::unique(ans.begin(), ans.end());
        ans.erase(last, ans.end());

        return ans;
    }
};