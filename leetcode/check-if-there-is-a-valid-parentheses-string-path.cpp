class Solution {
    
    int numOpen;
    
    bool push(char c) {
        if (c == '(') {
            ++numOpen;
        }
        else {
            if (numOpen == 0)
                return false;
            --numOpen;
        }
        return true;
    }
    
    void pop(char c) {
        if (c == '(') {
            --numOpen;
            assert(numOpen >= 0);
        }
        else {
            ++numOpen;
        }
    }
    
    char dp[101][101][202];
    int m, n;
    vector<vector<char>> grid;
    bool dfs(int i, int j) {
        if (i >= m || j >= n)
            return false;
        if (dp[i][j][numOpen] != -1)
            return dp[i][j][numOpen];
        if (i == m-1 && j == n-1)
            if (numOpen == 1)
                return true;
        bool yes = false;
        if (push(grid[i][j])) {
            yes = dfs(i+1, j) | dfs(i, j+1);
            pop(grid[i][j]);
        }
        return dp[i][j][numOpen] = yes;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid_) {
        memset(dp, -1, sizeof(dp));
        grid = move(grid_);
        m = grid.size();
        n = grid[0].size();
        if (grid[m-1][n-1] != ')')
            return false;
        return dfs(0, 0);
    }
};