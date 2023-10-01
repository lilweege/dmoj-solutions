class Solution {
    string_view palindromeAround(const string& s, int m, bool even) {
        int l = m, r = m + even;
        while (l >= 0 && r < s.length() && s[l] == s[r])
            --l, ++r;
        int n = r - l - 1;
        if (n < 0) return ""sv;
        if (n == 0) return string_view{s.data()+l, 1}; // never optimal
        return string_view{s.data()+m-(n-1)/2, size_t(n)};
    }
public:
    string longestPalindrome(const string& s) {
        int n = s.size();
        auto best = ""sv;
        for (int i = 0; i < n; ++i) {
            auto o = palindromeAround(s, i, false);
            auto e = palindromeAround(s, i, true);
            auto ss = (o.size() > e.size() ? o : e);
            if (ss.size() > best.size())
                best = ss;
        }
        return string{best};
    }
};