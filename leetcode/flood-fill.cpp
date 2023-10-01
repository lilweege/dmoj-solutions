class Solution {
    int m, n;
    int orig, color;
    vector<vector<int>> image;
    void dfs(int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (image[i][j] == orig) {
            image[i][j] = color;
            dfs(i+1, j);
            dfs(i-1, j);
            dfs(i, j+1);
            dfs(i, j-1);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int col) {
        image = img;
        m = image.size();
        n = image[0].size();
        orig = image[sr][sc];
        color = col;
        if (color == orig) return image;
        dfs(sr, sc);
        return image;
    }
};