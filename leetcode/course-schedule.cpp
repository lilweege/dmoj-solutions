// https://leetcode.com/problems/course-schedule

class Solution {
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<bool> rec;
    
    bool cycle(int u) {
        if (vis[u])
            return false;
        
        vis[u] = rec[u] = true;
        
        for (const int& v : adj[u])
            if (!vis[v] && cycle(v) || rec[v])
                return true;
        
        return rec[u] = false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses), vis.resize(numCourses), rec.resize(numCourses);
        
        for (const vector<int>& prereq : prerequisites)
            adj[prereq[0]].push_back(prereq[1]);
        
        for (int i = 0; i < numCourses; ++i)
            if (cycle(i))
                return false;
        return true;
    }
};