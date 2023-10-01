class Solution {
    bool vis[2001];
    bool stk[2001];
    vector<vector<int>> adj;
    bool hascycle(int u) {
        if (!vis[u]) {
            vis[u] = true;
            stk[u] = true;
            for (int v : adj[u]) {
                if (!vis[v])
                    if (hascycle(v))
                        return true;
                if (stk[v])
                    return true;
            }
            stk[u] = false;
        }
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        adj.clear();
        adj.resize(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        memset(vis, 0, numCourses);
        memset(stk, 0, numCourses);
        for (int i = 0; i < numCourses; ++i) {
            if (hascycle(i))
                return false;
        }
        return true;
    }
};