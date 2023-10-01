class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[127]{};
        for (char c : s) ++cnt[c];
        int n = 0;
        bool odd = false;
        for (int i = 0; i < 127; ++i)
            if (cnt[i] % 2 == 1)
                odd = true;
        for (int i = 0; i < 127; ++i)
            if (cnt[i] % 2 == 0)
                n += cnt[i];
            else n += cnt[i]-1;
        return n + odd;
    }
};