class Solution {
public:
    vector<int> minOperations(string s) {
        vector<int> ans;
        
        int n = s.size();
        ans.resize(n);
        if (n == 1) return ans;
        
        vector<int> l(n), r(n);
        l.resize(n);
        r.resize(n);
        
        for (int i = 1; i < n; ++i)
            l[i] = l[i-1] + (s[i-1] == '1');
        for (int i = n-2; i >= 0; --i)
            r[i] = r[i+1] + (s[i+1] == '1');
        
        for (int i = 1; i < n; ++i)
            l[i] += l[i-1];
        for (int i = n-2; i >= 0; --i)
            r[i] += r[i+1];
        
        for (int i = 0; i < n; ++i)
            ans[i] = l[i] + r[i];
        
        return ans;
    }
};