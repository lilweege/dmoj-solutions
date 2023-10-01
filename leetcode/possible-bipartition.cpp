class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(N + 1, vector<int>(0));
        for (const vector<int>& dl : dislikes) {
            adj[dl[0]].push_back(dl[1]);
            adj[dl[1]].push_back(dl[0]);
        }
        
        vector<bool> vis(N + 1, false);
        vector<int> group(N + 1, 0);
        
        for (int i = 1; i <= N; ++i) {
            if (vis[i])
                continue;
            
            group[i] = 1;
            queue<int> q; q.push(i);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (vis[u])
                    continue;
                vis[u] = true;
                
                for (int v : adj[u]) {
                    if (group[v] == group[u])
                        return false;
                    group[v] = group[u] == 1 ? 2 : 1;
                    q.push(v);
                }
            }
        }
        
        return true;
    }
};