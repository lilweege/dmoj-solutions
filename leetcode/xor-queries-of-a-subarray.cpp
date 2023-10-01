class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int m = queries.size();
        vector<int> l(n);
        l[0] = arr[0];
        for (int i = 1; i < n; ++i)
            l[i] = l[i-1] ^ arr[i];
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            int li = queries[i][0];
            int ri = queries[i][1];
            ans[i] = l[ri] ^ (li == 0 ? 0 : l[li-1]);
        }
        return ans;
    }
};