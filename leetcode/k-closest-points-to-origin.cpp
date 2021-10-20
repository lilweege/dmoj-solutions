// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
    int originDistance(const vector<int>& p) {
        return p[0] * p[0] + p[1] * p[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        multimap<int/*dst*/, int/*idx*/> m;
        
        for (int i = 0, n = points.size(); i < n; ++i)
            m.insert( { originDistance(points[i]), i } );
        
        
        vector<vector<int>> ans;
        for (auto it = m.begin(); it != m.end() && K; ++it, --K)
            ans.push_back(points[it->second]);
        
        return ans;
    }
};