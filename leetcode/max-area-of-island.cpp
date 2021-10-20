// https://leetcode.com/problems/max-area-of-island

class Solution {
    
    int m, n;
    
    const vector<pair<int, int>> offsets = {
        {  0, -1 },
        {  0,  1 },
        { -1,  0 },
        {  1,  0 },
    };
    
    int dfs(const vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j) {
        if (vis[j][i])
            return 0;
        vis[j][i] = true;
        
        int num = 1;
        for (auto [oi, oj] : offsets) {
            int x = i + oi,
                y = j + oj;
            if (x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if (grid[y][x]) {
                num += dfs(grid, vis, x, y);
            }
        }
        return num;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        
        int ans = 0;
        for (int j = 0; j < m; ++j)
            for (int i = 0; i < n; ++i)
                if (grid[j][i])
                    ans = max(ans, dfs(grid, vis, i, j));
        return ans;
    }
};