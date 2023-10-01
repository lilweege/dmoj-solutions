class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double, int>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].emplace_back(log(succProb[i]), edges[i][1]);
            adj[edges[i][1]].emplace_back(log(succProb[i]), edges[i][0]);
        }

        priority_queue<pair<double, int>> pq;
        vector<double> best(n, -INFINITY);
        pq.emplace(0, start);
        best[start] = 0;
        while (!pq.empty()) {
            auto [prob, u] = pq.top(); pq.pop();
            for (auto [w, v] : adj[u]) {
                double newProb = prob + w;
                if (newProb > best[v]) {
                    pq.emplace(newProb, v);
                    best[v] = newProb;
                }
            }
        }

        return exp(best[end]);
    }
};