class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        int n = points.size();
        vector<pair<float, int>> dist(n);
        for (int i = 0; i < n; ++i) {
            int x = points[i][0];
            int y = points[i][1];
            dist[i] = { sqrt(x*x + y*y), i };
        }
        sort(dist.begin(), dist.end());
        for (int i = 0; i < k; ++i)
            ans.push_back(points[dist[i].second]);
        return ans;
    }
};