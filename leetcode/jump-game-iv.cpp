class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = size(arr);
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; ++i)
            m[arr[i]].push_back(i);
        
        vector<bool> vis(n);
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        while (!empty(q)) {
            auto [step, cur] = q.front(); q.pop();
            if (cur < 0 || cur >= n)
                continue;
            if (vis[cur])
                continue;
            vis[cur] = true;
            if (cur == n-1)
                return step;
            auto p = m.find(arr[cur]);
            if (p != end(m)) {
                for (int x : p->second)
                    q.emplace(step+1, x);
                m.erase(p);
            }
            q.emplace(step+1, cur+1);
            q.emplace(step+1, cur-1);
        }
        return -1;
    }
};