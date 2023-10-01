class Solution {
    #define MAX_N 2000
    
    vector<int> par, rnk;
    int find(int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rnk[a] > rnk[b]) {
            par[b] = a;
        }
        else if (rnk[a] < rnk[b]) {
            par[a] = b;
        }
        else {
            par[b] = a;
            rnk[a]++;
        }
    }
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions_, vector<vector<int>>& requests) {
        rnk.resize(n);
        par.resize(n);
        fill(rnk.begin(), rnk.end(), 0);
        iota(par.begin(), par.end(), 0);
        
        vector<bitset<MAX_N>> friends(n), restrictions(n);
        for (int i = 0; i < n; ++i)
            friends[i][i] = true;
        for (auto& vv: restrictions_) {
            restrictions[vv[0]][vv[1]] = true;
            restrictions[vv[1]][vv[0]] = true;
        }
        
        vector<bool> ans(requests.size());
        for (int i = 0; i < requests.size(); ++i) {
            int u = find(requests[i][0]);
            int v = find(requests[i][1]);

            if (connected(u, v)) {
                ans[i] = true;
                continue;
            }
            
            if ((friends[u] & restrictions[v]).any() ||
                (friends[v] & restrictions[u]).any())
                continue;

            ans[i] = true;
            merge(u, v);
            friends[find(u)] = friends[u] | friends[v];
            restrictions[find(u)] = restrictions[u] | restrictions[v];
        }
        
        return ans;
    }
};
