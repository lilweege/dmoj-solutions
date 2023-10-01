class Solution {
    vector<int> par, rnk;

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (x < y) swap(x, y);
        par[y] = x;
        if (rnk[x] == rnk[y])
            rnk[x]++;
    }

public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList_, vector<vector<int>>& queries_) {
        par.resize(n);
        rnk.resize(n);
        iota(begin(par), end(par), 0);
        fill(begin(rnk), end(rnk), 0);


        vector<tuple<int, int, int>> edges;
        edges.reserve(edgeList_.size());
        for (const auto& ed : edgeList_) {
            edges.emplace_back(ed[2], ed[0], ed[1]);
        }
        sort(begin(edges), end(edges));

        vector<tuple<int, int, int, int>> queries;
        queries.reserve(queries_.size());
        for (int i = 0; i < queries_.size(); ++i) {
            const auto& q = queries_[i];
            queries.emplace_back(q[2], q[0], q[1], i);
        }
        sort(begin(queries), end(queries));


        vector<bool> ans(queries.size());
        int edgeIdx = 0;
        for (auto [d, p, q, i] : queries) {
            for (; edgeIdx < edges.size() && get<0>(edges[edgeIdx]) < d; ++edgeIdx)
                merge(get<1>(edges[edgeIdx]), get<2>(edges[edgeIdx]));
            ans[i] = find(p) == find(q);
        }

        return ans;
    }
};