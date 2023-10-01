class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> colLine(n), rowLine(n);
        for (int i = 0; i < n; ++i) {
            int lim = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > lim)
                    lim = grid[i][j];
            }
            colLine[i] = lim;
        }
        for (int j = 0; j < n; ++j) {
            int lim = 0;
            for (int i = 0; i < n; ++i) {
                if (grid[i][j] > lim)
                    lim = grid[i][j];
            }
            rowLine[j] = lim;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int lim = min(rowLine[j], colLine[i]);
                ans += lim - grid[i][j];
            }
        }

        return ans;
    }
};