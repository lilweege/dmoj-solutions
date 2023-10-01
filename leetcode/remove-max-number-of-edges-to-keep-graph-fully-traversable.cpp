class Solution {
    class DS {
        vector<int> par, rnk;
    public:
        DS(int n) : par(n), rnk(n) {
            iota(begin(par), end(par), 0);
        }

        int find(int x) {
            if (par[x] == x) return x;
            return par[x] = find(par[x]);
        }

        bool merge(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return false;
            if (x < y) swap(x, y);
            par[y] = x;
            if (rnk[x] == rnk[y])
                rnk[x]++;
            return true;
        }

        bool connected(int x, int y) {
            return find(x) == find(y);
        }
    };
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DS ds1(n);
        int cnt = 0;
        vector<pair<int, int>> t1, t2;
        for (const auto& ed : edges)
            switch (ed[0]) {
                case 1: t1.emplace_back(ed[1]-1, ed[2]-1); break;
                case 2: t2.emplace_back(ed[1]-1, ed[2]-1); break;
                default: cnt += ds1.merge(ed[1]-1, ed[2]-1); break;
            }
        DS ds2(ds1);
        for (auto [x, y] : t1) cnt += ds1.merge(x, y);
        for (auto [x, y] : t2) cnt += ds2.merge(x, y);
        for (int i = 1; i < n; ++i)
            if (!ds1.connected(i-1, i) || !ds2.connected(i-1, i))
                return -1;
        return edges.size() - cnt;
    }
};