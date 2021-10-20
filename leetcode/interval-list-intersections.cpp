// https://leetcode.com/problems/interval-list-intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int n = A.size(), m = B.size(), i = 0, j = 0;
        while (i < n && j < m) {
            int lo = max(A[i][0], B[j][0]),
                hi = min(A[i][1], B[j][1]);
            if (lo <= hi)
                ans.push_back( {lo, hi} );
            
            ++(A[i][1] < B[j][1] ? i : j);
        }
        return ans;
    }
};