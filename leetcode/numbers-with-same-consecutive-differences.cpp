class Solution {
    void dfs(vector<int>& ans, int n, int k, int last, int x) {
        if (n == 0) {
            ans.push_back(x);
            return;
        }
        
        int a = last + k;
        if (a <= 9)
            dfs(ans, n - 1, k, a, x * 10 + a);
        if (k != 0) {
            int b = last - k;
            if (b >= 0)
                dfs(ans, n - 1, k, b, x * 10 + b);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        for (int first = 1; first <= 9; ++first)
            dfs(ans, n - 1, k, first, first);
        
        return ans;
    }
};