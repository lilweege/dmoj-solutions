class Solution {
    void dfs(vector<vector<int>>& res, vector<vector<int>>& vis, const vector<vector<int>>& heights, int preval, int ni, int nj, int pi, int pj, int m, int n) {
        if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
            return;
        }
        int nxtHeight = heights[ni][nj];
        int prvHeight = heights[pi][pj];
        if (nxtHeight < prvHeight) {
            return;
        }
        if ((vis[ni][nj] & preval) == preval) {
            return;
        }
        vis[ni][nj] |= preval;
        if (vis[ni][nj] == 3) {
            res.push_back({ni, nj});
        }
        dfs(res, vis, heights, vis[ni][nj], ni+1, nj, ni, nj, m, n);
        dfs(res, vis, heights, vis[ni][nj], ni-1, nj, ni, nj, m, n);
        dfs(res, vis, heights, vis[ni][nj], ni, nj+1, ni, nj, m, n);
        dfs(res, vis, heights, vis[ni][nj], ni, nj-1, ni, nj, m, n);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> res;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            dfs(res, vis, heights, 1, i,   0, i,   0, n, m);
            dfs(res, vis, heights, 2, i, n-1, i, n-1, n, m);
        }
        for (int j = 0; j < n; ++j) {
            dfs(res, vis, heights, 1,   0, j,   0, j, n, m);
            dfs(res, vis, heights, 2, m-1, j, m-1, j, n, m);
        }
        return res;
    }
};