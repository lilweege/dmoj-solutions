class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt[127]{};
        int i = 0, j = 0;
        int n = s.size();
        int best = 0;
        while (j < n) {
            char c = s[j];
            if (cnt[c] == 0) {
                ++cnt[c];
                ++j;
            }
            else {
                --cnt[s[i]];
                ++i;
            }
            best = max(best, j-i);
        }
        return best;
    }
};