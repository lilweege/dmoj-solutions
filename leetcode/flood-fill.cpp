// https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> img;
    int srcColor, newColor;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int _newColor) {
        img = image;
        srcColor = image[sr][sc];
        newColor = _newColor;
        fillColor(sr, sc);
        return img;
    }
    
    void fillColor(int r, int c) {
        if (r < 0 || r >= img.size() || c < 0 || c >= img[0].size() || img[r][c] == newColor || img[r][c] != srcColor)
            return;
        img[r][c] = newColor;
        fillColor(r + 1, c);
        fillColor(r - 1, c);
        fillColor(r, c + 1);
        fillColor(r, c - 1);
    }
};