class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (n > m) return "";
        int cnt[128]{};
        for (char c : t) ++cnt[c];
        int best = 1<<30;
        int start = 0;
        int num = 0;
        int i = 0, j = 0;
        while (j < m) {
            char c = s[j++];
            int x = --cnt[c];
            if (x >= 0) {
                ++num;
            }
            while (num == n) {
                if (j - i < best) {
                    best = j - i;
                    start = i;
                }
                char c = s[i++];
                int x = cnt[c]++;
                if (x == 0) {
                    --num;
                    break;
                }
            }
        }
        if (best == 1<<30) return "";
        return s.substr(start, best);
    }
};