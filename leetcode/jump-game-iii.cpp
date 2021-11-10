// https://leetcode.com/problems/jump-game-iii

class Solution {
    vector<int> vis;
    bool dfs(const vector<int>& arr, int n, int cur) {
        if (cur < 0 || cur >= n)
            return false;
        if (vis[cur])
            return false;
        vis[cur] = true;
        if (arr[cur] == 0)
            return true;
        return dfs(arr, n, cur + arr[cur]) | dfs(arr, n, cur - arr[cur]);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = size(arr);
        vis.resize(n);
        return dfs(arr, n, start);
    }
};