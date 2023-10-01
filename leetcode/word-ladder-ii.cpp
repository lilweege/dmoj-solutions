
class Solution {
public:
    
    static bool offByOne(string_view a, string_view b) {
        int n = a.size();
        int d = 0;
        for (int i = 0; i < n; ++i)
            if ((d += (a[i] != b[i])) == 2)
                return false;
        return d == 1;
    }
    
    // reversed
    void dfs(int cur, int fr, int to, vector<int>& path, const vector<vector<int>> adj, const vector<string>& vals, vector<vector<string>>& out)
    {
        if (cur == to) {
            out.emplace_back();
            auto& ans = out.back();
            for (int i = path.size()-1; i >= 0; --i)
                ans.push_back(vals[path[i]]);
            ans.push_back(vals[fr]);
            return;
        }
        for (int nxt : adj[cur]) {
            path.push_back(nxt);
            dfs(nxt, fr, to, path, adj, vals, out);
            path.pop_back();
        }
    }
    
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> paths;
        
        wordList.push_back(beginWord);
        int begin = wordList.size()-1;
        int n = wordList.size();
        
        int end = -1;
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord) {
                end = i;
                break;
            }
        }
        if (end == -1)
            return paths;
        
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (offByOne(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        
        vector<int> dist(n, -1);
        vector<vector<int>> prev(n);
        
        int depth = 0;
        queue<int> q;
        q.push(begin);
        while (!q.empty()) {
            for (int s = q.size(); s--;) {
                int i = q.front(); q.pop();
                for (int j : adj[i]) {
                    if (dist[j] == -1) {
                        // first time
                        dist[j] = depth;
                        prev[j].push_back(i);
                        q.push(j);
                    }
                    else if (dist[j] == depth) {
                        // not first time
                        prev[j].push_back(i);
                    }
                }
            }
            ++depth;
        }
        
        {
            vector<int> path;
            dfs(end, end, begin, path, prev, wordList, paths);
        }
        
        return paths;
    }
};