// https://leetcode.com/problems/minimum-path-sum

#define pi pair<int, int>
#define pii pair<int, pi>

class Solution {
    bool pointRect(int px, int py, int rx, int rw, int ry, int rh) {
        return (rx <= px) && (px < (rx + rw)) && (ry <= py) && (py < (ry + rh));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();

        vector<pi> transform = { {0, 1}, {1, 0} };
        vector<vector<bool>> vis(r, vector<bool>(c));
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({ grid[0][0], { 0, 0 } });


        while (!q.empty()) {
            pii cur = q.top(); q.pop();
            int cy = cur.second.first, cx = cur.second.second, w = cur.first;
            if (!vis[cy][cx]) {
                vis[cy][cx] = true;
                if (cy == r - 1 && cx == c - 1) return w;
                for (pi t : transform) {
                    int ny = cy + t.first, nx = cx + t.second;
                    if (pointRect(nx, ny, 0, c, 0, r)) {
                        q.push({ grid[ny][nx] + w, { ny, nx } });
                    }
                }
            }
        }
        return 0;
    }
};