class Solution {
    vector<vector<int>> adj;
    int dep1 = 0;
    int far1 = 0;
    int dep2 = 0;
    int far2 = 0;
    
    void dfs1(int fr, int me, int dep=0) {
        if (dep > dep1) {
            dep1 = dep;
            far1 = me;
        }
        for (int to : adj[me])
            if (to != fr)
                dfs1(me, to, dep+1);
    }
    void dfs2(int fr, int me, int dep=0) {
        if (dep > dep2) {
            dep2 = dep;
            far2 = me;
        }
        for (int to : adj[me])
            if (to != fr)
                dfs2(me, to, dep+1);
    }
    bool dfs3(int fr, int me, vector<int>& ans, int dep=0) {
        if (me == far1) return true;
        bool gotTarget = false;
        for (int to : adj[me])
            if (to != fr)
                gotTarget |= dfs3(me, to, ans, dep+1);
        if (gotTarget) {
            if ((!(dep2 & 1) && dep == dep2/2) || ((dep2 & 1) && (dep == dep2/2 || dep == dep2/2+1))) {
                ans.push_back(me);
            }
        }
        return gotTarget;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for (auto& vv : edges) {
            int u = vv[0], v = vv[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(0, 0);
        dfs2(far1, far1);
        // cout << "far1 = " << far1 << '\n';
        // cout << "far2 = " << far2 << '\n';
        if (dep2 == 0) return {0};
        if (dep2 == 1) return {0, 1};
        vector<int> ans;
        dfs3(far2, far2, ans);
        return ans;
    }
};