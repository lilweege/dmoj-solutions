class Solution {
    /*
    int brute(const vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size(), sz = min(n, m);
        
        int cnt = 0;
        for (int sq = 0; sq < sz; ++sq)
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    if (satisfySquare(matrix, i, j, sq))
                        ++cnt;
        return cnt;
    }
    bool satisfySquare(const vector<vector<int>>& matrix, int r, int c, int sq) {
        int m = r + sq, n = c + sq;
        if (m >= matrix.size() || n >= matrix[0].size())
            return false;
        for (int i = r; i <= m; ++i)
            for (int j = c; j <= n; ++j)
                if (matrix[i][j] == 0)
                    return false;
        return true;
    }
    */
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i && j && matrix[i][j])
                    matrix[i][j] += min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1]));
                cnt += matrix[i][j];
            }
        }
        return cnt;
    }
};