class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int cnt[127]{};
        for (int i = 0; i < s.size(); ++i) {
            ++cnt[s[i]];
            --cnt[t[i]];
        }
        for (int i = 0; i < 127; ++i)
            if (cnt[i] != 0) return false;
        return true;
    }
};