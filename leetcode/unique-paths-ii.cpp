class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[m-1][n-1] == 1) return 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                grid[i][j] *= -1;

        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == -1) break;
            grid[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == -1) break;
            grid[0][j] = 1;
        }

        if (m == 1 || n == 1)
            return grid[m-1][n-1];

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] == -1) continue;
                grid[i][j] = max(grid[i-1][j], 0) + max(grid[i][j-1], 0);
            }
        }
        return grid[m-1][n-1];
    }
};