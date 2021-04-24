class Solution {
    
    
    // 0 water
    // 1 land
    // 2 vis
    
    int m, n;

	vector<pair<int, int>> transform = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    
    int dfsLand(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] == 0)
            return 0;
        int c = 1;
        grid[i][j] = 2;
        for (auto [y, x] : transform) {
            y += i;
            x += j;
            if (y >= 0 && y < m && x >= 0 && x < n) {
                if (grid[y][x] == 1) {
                    c += dfsLand(grid, y, x);
                }
            }
        }
        return c;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        
        int best = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    best = max(best, dfsLand(grid, i, j));
            }
        }
        
        return best;
    }
};