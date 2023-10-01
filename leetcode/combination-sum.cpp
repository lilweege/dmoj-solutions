class Solution {
    int target;
    vector<vector<int>> ans;
    vector<int> v;
    vector<int> candidates;
    void dfs(int j=0, int sum=0) {
        if (sum == target) {
            ans.push_back(v);
        }
        else {
            for (int i = j; i < size(candidates); ++i) {
                int x = candidates[i];
                if (sum + x <= target) {
                    v.push_back(x);
                    dfs(i, sum + x);
                    v.pop_back();
                }
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates_, int target_) {
        candidates = candidates_;
        target = target_;
        dfs();
        return ans;
    }
};
