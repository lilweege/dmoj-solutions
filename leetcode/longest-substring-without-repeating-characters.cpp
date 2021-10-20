// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // // naive
        // int n = size(s);
        // unordered_map<char, bool> cnt;
        // int best = 0;
        // for (int i = 0; i < n; ++i) {
        //     int x = 0;
        //     for (int j = i; j < n; ++j) {
        //         char c = s[j];
        //         if (cnt[c])
        //             break;
        //         cnt[c] = true;
        //         ++x;
        //     }
        //     cnt.clear();
        //     best = max(best, x);
        // }
        // return best;
        
        int n = size(s);
        vector<bool> has;
        has.resize(200);
        int x = 0, best = 0;
        for (int i = 0, j = 0; j < n;) {
            while (has[s[j]]) {
                has[s[i++]] = false;
                --x;
            }
            has[s[j++]] = true;
            best = max(best, ++x);
        }
        return best;
    }
};