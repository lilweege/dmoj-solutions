class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), m = p.size();
        if (m > n) return {};
        int cnt[26]{};
        for (char c : p) --cnt[c-'a'];
        
        for (int i = 0; i < m; ++i)
            ++cnt[s[i]-'a'];

        auto check_ok = [&](int i) {
            bool yes = true;
            for (int j = 0; j < 26; ++j)
                if (cnt[j] != 0) {
                    yes = false;
                    break;
                }
            if (yes) ans.push_back(i);
        };
        check_ok(0);
        for (int i = m; i < n; ++i) {
            --cnt[s[i-m]-'a'];
            ++cnt[s[i]-'a'];
            check_ok(i-m+1);
        }
        return ans;
    }
};