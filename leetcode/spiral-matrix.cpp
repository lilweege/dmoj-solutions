class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans(m*n);
        int cnt = 0;
        if (m == 1) return matrix[0];
        if (n == 1) {
            for (auto& v : matrix)
                ans[cnt++] = v[0];
            return ans;
        }

        int dir = 0; // 0123 -> RDLU
        int i = 0, j = -1;
        int ri = m-1, rj = n;
        int run = 0;
        while (cnt < m*n) {
            ++run;
            if (dir == 0) { // r
                ++j;
                if (run == rj) {
                    run = 0;
                    --rj;
                    dir = (dir + 1) % 4;
                }
            }
            else if (dir == 1) { // d
                ++i;
                if (run == ri) {
                    run = 0;
                    --ri;
                    dir = (dir + 1) % 4;
                }
            }
            else if (dir == 2) { // l
                --j;
                if (run == rj) {
                    run = 0;
                    --rj;
                    dir = (dir + 1) % 4;
                }
            }
            else { // u
                --i;
                if (run == ri) {
                    run = 0;
                    --ri;
                    dir = (dir + 1) % 4;
                }
            }
            // cout << i << ' ' << j << '\n';
            // if (i < 0 || i >= m || j < 0 || j >= n) {cout <<"BREAK\n";break;}
            ans[cnt++] = matrix[i][j];
        }
        return ans;
    }
};