class Solution {
    static constexpr array<pair<int, int>, 4> dirs{{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == 0)
                    q.emplace(i, j);
                else
                    mat[i][j] = -1; // unvis

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (auto [di, dj] : dirs) {
                int ni = i+di, nj = j+dj;
                if (0 <= ni && ni < m && 0 <= nj && nj < n && mat[ni][nj] == -1) {
                    mat[ni][nj] = mat[i][j] + 1;
                    q.emplace(ni, nj);
                }
            }
        }

        return mat;
    }
};