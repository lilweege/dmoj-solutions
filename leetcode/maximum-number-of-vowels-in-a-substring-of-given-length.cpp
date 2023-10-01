class Solution {
    bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            cnt += isvowel(s[i]);
        }
        int ans = cnt;
        for (int i = k; i < n; ++i) {
            cnt -= isvowel(s[i-k]);
            cnt += isvowel(s[i]);
            ans = max(ans, cnt);
        }
        return ans;
    }
};