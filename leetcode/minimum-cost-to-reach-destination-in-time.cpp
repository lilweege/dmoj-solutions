class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        
        int m = edges.size();
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < m; ++i) {
            int x = edges[i][0];
            int y = edges[i][1];
            int t = edges[i][2];
            adj[x].emplace_back(t, y);
            adj[y].emplace_back(t, x);
        }
        
        
        vector<int> cost(1001, 1<<30);
        vector<int> time(1001, 1<<30);
        // cost, time, city
        using xx = tuple<int, int, int>;
        priority_queue<xx, vector<xx>, greater<xx>> pq;
        pq.emplace(passingFees[0], 0, 0);
        while (!pq.empty()) {
            auto [c, t, x] = pq.top(); pq.pop();
            // cout << c << ' ' << t << ' ' << x << '\n';
            for (auto [dt, y] : adj[x]) {
                auto nt = t + dt;
                auto nc = c + passingFees[y];
                if (nt <= maxTime) {
                    if (y == n-1) return nc;
                    bool bt = nt < time[y];
                    bool bc = nc < cost[y];
                    if (bt || bc) {
                        if (bc) cost[y] = nc;
                        if (bt) time[y] = nt;
                        pq.emplace(nc, nt, y);
                    }
                }
            }
        }
        
        return -1;
    }
};