class Solution {
    vector<vector<int>> grid;
    int n, m;
    int ans;
    int pathLen;
public:
    void dfs(int x, int y, int cnt=0) {
        if (x < 0 || x >= m || y < 0 || y >= n)
            return;

        if (grid[x][y] == -1)
            return;
        
        if (grid[x][y] == 2) {
            if (cnt == pathLen)
                ++ans;
            return;
        }
        
        grid[x][y] = -1;
        dfs(x+1, y, cnt+1);
        dfs(x-1, y, cnt+1);
        dfs(x, y+1, cnt+1);
        dfs(x, y-1, cnt+1);
        grid[x][y] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid_) {
        grid = move(grid_);
        m = grid.size();
        n = grid[0].size();
        pathLen = 1;
        int sx, sy;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    sx = i, sy = j;
                else if (grid[i][j] == 0)
                    ++pathLen;
            }
        }
        ans = 0;
        dfs(sx, sy);
        return ans;
    }
};