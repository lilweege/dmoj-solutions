// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        if (n > m) return {};
        
        vector<int> indecies;
        vector<int> diff(26);
        for (int i = 0; i < n; ++i) {
            --diff[p[i] - 'a'];
            ++diff[s[i] - 'a'];
        }
        
        for (int i = 0; i < m - n; ++i) {
            if (!any_of(diff.begin(), diff.end(), [](int x) { return x; }))
                indecies.push_back(i);
            --diff[s[i] - 'a'];
            ++diff[s[i + n] - 'a'];
        }
        if (!any_of(diff.begin(), diff.end(), [](int x) { return x; }))
            indecies.push_back(m - n);

        return indecies;
    }
};